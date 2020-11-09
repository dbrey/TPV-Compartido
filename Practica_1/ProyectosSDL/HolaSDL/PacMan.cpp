
#include "PacMan.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include "GameMap.h"

PacMan::PacMan(int x, int y, Game* g) : iniPoint(y,x), point(y, x) {
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
					ds = l;

				break;
			}
			case SDLK_RIGHT:
			{
				if(game->getMapa()->readCell(point.getX() + 1, point.getY()) != Wall)
					ds = r;
					break;
			}
			case SDLK_UP:
			{
				if(game->getMapa()->readCell(point.getX(), point.getY() - 1) != Wall)
					ds = u;

					break;
			}
			case SDLK_DOWN:
			{
				if(game->getMapa()->readCell(point.getX(), point.getY() + 1) != Wall)
					ds = d;

					break;
			}
		}
		comida();
	}
}

void PacMan::update()
{
	switch (ds)
	{
	case l:
	{
		dir.izquierda();
		if (point.getX() == 0 && point.getY() == 16)
		{
			point.SetPos(27, 16);
		}
		break;
	}
	case r:
	{
		dir.derecha();
		if (point.getX() == 27 && point.getY() == 16)
		{
			point.SetPos(0, 16);
		}
		break;
	}
	case u:
	{
		dir.arriba();
		break;
	}
	case d:
	{
		dir.abajo();
		break;
	}
	default:
		break;
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



