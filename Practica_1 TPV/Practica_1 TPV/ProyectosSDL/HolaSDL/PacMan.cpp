
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
				if (game->getMapa()->readCell(point.getX() - 1, point.getY()) != Wall)
					point.Suma(-1, 0);
				break;
			}
			case SDLK_RIGHT:
			{
				if(game->getMapa()->readCell(point.getX() + 1, point.getY()) != Wall)
					point.Suma(1, 0);
					break;
			}
			case SDLK_UP:
			{
				if(game->getMapa()->readCell(point.getX(), point.getY() - 1) != Wall)
					point.Suma(0, -1);
					break;
			}
			case SDLK_DOWN:
			{
				if(game->getMapa()->readCell(point.getX(), point.getY() + 1) != Wall)
					point.Suma(0, 1);
					break;
			}
		}
		comida();
	}
}

/*void PacMan::update()
{

}*/

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

