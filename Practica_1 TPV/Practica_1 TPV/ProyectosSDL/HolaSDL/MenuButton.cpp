#include "MenuButton.h"
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>


MenuButton::MenuButton(const LoaderParams* pParams) :

	SDLGameObject(pParams)
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
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
		if () //COMPROBAR SI ES CLICK IZQUIERDO
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}