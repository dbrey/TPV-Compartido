
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
		tiempoforce = duracion;
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

void PacMan::check() {
	// Comprobamos si el pacman ha hecho contacto con un fantasmas
	for (int i = 0; i < 4; i++) {
		if (point.iguales(game->getGhost(i)->getPoint())) {
			if (tiempoforce == 0) {
				morir();
			}
			else {
				game->getGhost(i)->morir();
			}
		}
	}
}

void PacMan::update() {
	check();
	if (game->nextCell(dir,point)) {
		dir.movimiento(point);
		comida();
		check();
	}

	if (tiempoforce > 0) {
		tiempoforce--;
	}
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
		if (tiempoforce == 0)
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