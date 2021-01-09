#include "MenuButton.h"
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>

void MenuButton::draw()
{
	//SDLGameObject::draw(); // use the base class drawing
}

bool MenuButton::handleEvent()
{
	POINT cursor; //Obtener posicion del raton

	GetCursorPos(&cursor);

	Vector2D pMousePos(cursor.x, cursor.y);


	if (pMousePos.GetX() < (point.getX() + w) //Si esta dentro del boton
		&& pMousePos.GetX() > point.getX()
		&& pMousePos.GetX() < (point.getY() + h) //m_position es el boton
		&& pMousePos.GetX() > point.getY())
	{
		m_currentFrame = MOUSE_OVER;

		/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT))  //COMPROBAR SI ES CLICK IZQUIERDO
		{
			m_currentFrame = CLICKED;
			stMachine->changeState(play);  // Cambiamos de estado de juego a PlayState
			return true;
		}*/
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
		return false;
	}
}

void MenuButton::clean()
{
	
}

