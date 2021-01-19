#include "MenuButton.h"
#include <stdio.h>



bool MenuButton::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) // Pulsa el raton
	{
		
												
		SDL_Point p;
		p.x = event.button.x;
		p.y = event.button.y;


		SDL_Rect r = getDestRect();

		if (SDL_PointInRect(&p, &r) == SDL_TRUE) // P ES RATON Y R EL RECTANGULO DEL BOTON
		{
			cboq(game);
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


