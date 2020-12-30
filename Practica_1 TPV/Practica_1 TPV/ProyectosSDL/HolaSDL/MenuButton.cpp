#include "MenuButton.h"
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>


MenuButton::MenuButton(const LoaderParams* pParams) :

	SDLGameObject(pParams)
{
	m_currentFrame = MOUSE_OUT; // Empezamos desde el primer frame
}

void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}


void MenuButton::update()
{
	POINT cursor; //Obtener posicion del raton

	GetCursorPos(&cursor);

	Vector2D pMousePos(cursor.x, cursor.y);


	if (pMousePos.GetX() < (m_position.getX() + Game::CellX) //Si esta dentro del boton
		&& pMousePos.GetX() > m_position.getX()
		&& pMousePos.GetX() < (m_position.getY() + Game::CellY) //m_position es el boton
		&& pMousePos.GetX() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if () // (TheInputHandler::Instance()->getMouseButtonState(LEFT) //COMPROBAR SI ES CLICK IZQUIERDO
		{
			m_currentFrame = CLICKED;

			// Cambiamos de estado de juego a PlayState
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}