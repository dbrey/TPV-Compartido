#include "MenuButton.h"
#include <stdio.h>


// Manejamos el evento correspondiente del boton
bool MenuButton::handleEvent(SDL_Event& event)
{
	// Si pulsa el boton izquierdo del raton
	if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) 
	{			
		// Cogemos la posicion del raton
		SDL_Point p;
		p.x = event.button.x;
		p.y = event.button.y;

		SDL_Rect r = getDestRect();

		// P ES RATON Y R EL RECTANGULO DEL BOTON
		if (SDL_PointInRect(&p, &r) == SDL_TRUE) 
		{
			cboq(game);
			return true;
		}
	}
	return false;
}

// Renderizamos el boton
void MenuButton::render()
{
	SDL_Rect rect = getDestRect();
	
	textura->renderFrame(rect, 0, 0);
}

// Cogemos el rect del boton
SDL_Rect MenuButton::getDestRect()
{
	SDL_Rect aux;
	aux.x = point.getX();
	aux.y = point.getY();

	aux.w = w;
	aux.h = h;
	return aux;
}


