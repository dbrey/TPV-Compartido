#include "MenuButton.h"
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>


bool MenuButton::handleEvent(SDL_Event& event)
{
	//Crear p y r


	// SDL_MOUSEBUTTONDOWN o SDL_MOUSEBUTTONUP? En el video de clase hace el segundo

	// No pilla el SDL_MOUSEBUTTONDOWN ni el event button
	
	

	if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) // Pulsa el raton
	{
		POINT raton;
		GetCursorPos(&raton);
												
		SDL_Point p;
		p.x = raton.x;
		p.y = raton.y;

		p.x *= 0.7;


		SDL_Rect r = getDestRect();
		/*r.x *= 1.80;
		r.y *= 1.25;
		//r.h *= 1.5;*/

		if (SDL_PointInRect(&p, &r) == SDL_TRUE) // P ES RATON Y R EL RECTANGULO DEL BOTON
		{
			cboq(game);
			//game->stMachine()->changeState();
			return true;
		}
	}
	return false;
}

void MenuButton::render()
{
	SDL_Rect rect = getDestRect();
	
	textura->renderFrame(rect, 0, 0);
}

SDL_Rect MenuButton::getDestRect()
{
	SDL_Rect aux;
	aux.x = point.getX();
	aux.y = point.getY();

	aux.w = w;
	aux.h = h;
	return aux;
}

void MenuButton::clean()
{
	
}

