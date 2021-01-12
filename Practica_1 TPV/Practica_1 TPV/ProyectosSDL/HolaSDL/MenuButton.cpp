#include "MenuButton.h"
#include "checkML.h"
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>

void MenuButton::draw()
{
	//SDLGameObject::draw(); // use the base class drawing
}

bool MenuButton::handleEvent(SDL_Event event)
{
	//Crear p y r
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) // Pulsa el raton
	{
		POINT raton;
		GetCursorPos(&raton);

		SDL_Point p;
		p.x = raton.x;
		p.y = raton.y;

		SDL_Rect r = getDestRect();
		// Necesitamos acceder al tamaño de los botones

		if (SDL_PointInRect(&p, &r) == SDL_TRUE) // P ES RATON Y R EL RECTANGULO DEL BOTON
		{
			cboq(game);
			//g->stMachine()->changeState();
			return true;
		}
	}
	return false;
}

void MenuButton::clean()
{
	
}

