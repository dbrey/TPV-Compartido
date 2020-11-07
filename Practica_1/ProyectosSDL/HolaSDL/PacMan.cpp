
#include "PacMan.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include "GameMap.h"

void PacMan::HandleEvent(SDL_Event tecla)
{
	if (tecla.type == SDL_KEYDOWN)
	{
		switch (tecla.key.keysym.sym)
		{
			case SDLK_LEFT:
			{
				if(mapa->readCell(point.getX() - 1, point.getY()) != Wall)
				dir.izquierda();

				break;
			}
			case SDLK_RIGHT:
			{
				if(mapa->readCell(point.getX() + 1, point.getY()) != Wall)
				dir.derecha();

					break;
			}
			case SDLK_UP:
			{
				if(mapa->readCell(point.getX(), point.getY() - 1) != Wall)
				dir.arriba();

					break;
			}
			case SDLK_DOWN:
			{
				if(mapa->readCell(point.getX(), point.getY() + 1) != Wall)
				dir.abajo();

					break;
			}
		}
	}
}

//void PacMan::Render()

