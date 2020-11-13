
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
	if (game->nextCell(dir))
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
	dir.setdir(0, 0);
	comida();
}

void PacMan::render() {
	SDL_Rect rect;
	rect.x = point.getX()*10;
	rect.y = point.getY()*10;
	rect.w = 10;
	rect.h = 10;
	textura->renderFrame(rect, 0, 11);
}

PacMan::~PacMan()
{
	delete game;
	delete textura;
}

