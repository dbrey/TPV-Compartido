
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
				if()
				dir.izquierda();

				break;
			}
			case SDLK_RIGHT:
			{
				//if(A la izquierda no hay muro)
				dir.derecha();

					break;
			}
			case SDLK_UP:
			{
				//if(A la izquierda no hay muro)
				dir.arriba();

					break;
			}
			case SDLK_DOWN:
			{
				//if(A la izquierda no hay muro)
				dir.abajo();

					break;
			}
		}
			



	}
}

void PacMan::Render()
{
	
}
