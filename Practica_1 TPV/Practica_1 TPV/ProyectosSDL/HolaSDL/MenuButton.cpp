#include "MenuButton.h"
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>

void MenuButton::draw()
{
	//SDLGameObject::draw(); // use the base class drawing
}

bool MenuButton::handleEvent(SDL_Event event)
{

	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) // Pulsa el raton
	{
		//Crear p y r
		SDL_Point p;

		SDL_Rect r;

		if (SDL_PointInRect(&p, &r) == SDL_TRUE) // P ES RATON Y R EL RECTANGULO DEL BOTON
		{
			cboq(game);
			//g->stMachine()->changeState();
			return true;
		}
	}
	return false;


	//POINT cursor; //Obtener posicion del raton

	//GetCursorPos(&cursor);

	//Vector2D pMousePos(cursor.x, cursor.y);


	//if (pMousePos.GetX() < (point.getX() + w) //Si esta dentro del boton
	//	&& pMousePos.GetX() > point.getX()
	//	&& pMousePos.GetX() < (point.getY() + h) //m_position es el boton
	//	&& pMousePos.GetX() > point.getY())
	//{
	//	m_currentFrame = MOUSE_OVER;

	//	/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT))  //COMPROBAR SI ES CLICK IZQUIERDO
	//	{
	//		m_currentFrame = CLICKED;
	//		stMachine->changeState(play);  // Cambiamos de estado de juego a PlayState
	//		return true;
	//	}*/
	//}
	//else
	//{
	//	m_currentFrame = MOUSE_OUT;
	//	return false;
	//}
}

void MenuButton::clean()
{
	
}

