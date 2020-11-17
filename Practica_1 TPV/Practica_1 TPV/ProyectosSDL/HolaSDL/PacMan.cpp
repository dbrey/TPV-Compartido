
#include "PacMan.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include "GameMap.h"

PacMan::PacMan(int x, int y, Game* g) : iniPoint(x,y), point(x, y) {
	game = g;
	textura = g->getTexture(characters);
}

void PacMan::comida() {
	if (game->getMapa()->readCell(point.getX(), point.getY()) == Food)
	{
		game->getMapa()->writeCell(point.getX(), point.getY(), Empty);
	}
	else if (game->getMapa()->readCell(point.getX(), point.getY()) == Vitamins)
	{
		game->getMapa()->writeCell(point.getX(), point.getY(), Empty);
		force = true;
	}
}

void PacMan::handleEvent(SDL_Event& tecla)
{
	if (tecla.type == SDL_KEYDOWN)
	{
		switch (tecla.key.keysym.sym)
		{
			case SDLK_LEFT:
			{
				dir.setdir(-1, 0);
				break;
			}
			case SDLK_RIGHT:
			{
				dir.setdir(1, 0);
				break;
			}
			case SDLK_UP:
			{
				dir.setdir(0, -1);
				break;
			}
			case SDLK_DOWN:
			{
				dir.setdir(0, 1);
				break;
			}
		}
	}

}

void PacMan::update()
{
	// Por alguna razon esto no funciona correctamente
	if (game->nextCell(dir,point))
	{
		if (dir.GetX() == -1) {
			point.Suma(-1, 0);
		}
		else if (dir.GetX() == 1) {
			point.Suma(1, 0);
		}
		else if (dir.GetY() == -1) {
			point.Suma(0, -1);
		}
		else if (dir.GetY() == 1) {
			point.Suma(0, 1);
		}
	}

	Point2D izq(0, 15);
	Point2D der(28, 15);
	if (point.iguales(izq))
	{
		point.SetPos(27, 15);
	}
	else if (point.iguales(der))
	{
		point.SetPos(1, 15);
	}

	// Comprobamos si el pacman ha hecho contacto con un fantasmas
	for (int i = 0; i < 4; i++)
	{
		if (point.iguales(game->getGhost(i)->getPoint()))
		{
			if (!force)
			{
				morir();
			}
			else
			{
				game->getGhost(i)->morir();
			}

		}
	}

	if (force)
	{
		tiempoforce++;
		if (tiempoforce >= duracion)
		{
			force = false;
			tiempoforce = 0;
		}
	}

	comida();
}

void PacMan::morir()
{
	vidas--;
	point = iniPoint;
}

void PacMan::render() {
	SDL_Rect rect;
	rect.x = point.getX()*10;
	rect.y = point.getY()*10;
	rect.w = 10;
	rect.h = 10;
	
	try {
		if (!force)
		{
			textura->renderFrame(rect, 0, 10);
		}
		else
		{
			textura->renderFrame(rect, 0, 11);
		}
	}
	catch (string& e)
	{
		if (textura == NULL)
		{
			e = "PacMan no tiene textura";
		}
		cout << e;

	}
	
}

PacMan::~PacMan()
{
	delete game;
	delete textura;
}

