
#include "PacMan.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include "GameMap.h"

PacMan::PacMan(int x, int y, Game* g) : iniPoint(y,x), point(y, x) {
	game = g;
	textura = g->getTexture(characters);
}

void PacMan::handleEvent(SDL_Event tecla)
{
	if (tecla.type == SDL_KEYDOWN)
	{
		switch (tecla.key.keysym.sym)
		{
			case SDLK_LEFT:
			{
				if(game->getMapa()->readCell(point.getX() - 1, point.getY()) != Wall)
				dir.izquierda();

				break;
			}
			case SDLK_RIGHT:
			{
				if(game->getMapa()->readCell(point.getX() + 1, point.getY()) != Wall)
				dir.derecha();

					break;
			}
			case SDLK_UP:
			{
				if(game->getMapa()->readCell(point.getX(), point.getY() - 1) != Wall)
				dir.arriba();

					break;
			}
			case SDLK_DOWN:
			{
				if(game->getMapa()->readCell(point.getX(), point.getY() + 1) != Wall)
				dir.abajo();

					break;
			}
		}
	}
}

void PacMan::render() {
	SDL_Rect rect;
	rect.x = point.getX()*10;
	rect.y = point.getY()*10;
	rect.w = 10;
	rect.h = 10;
	textura->renderFrame(rect, 0, 11);
}

