#pragma once
#include "GameObject.h"
#include "Game.h"

class Game;

class MenuButton: public SDLGameObjects
{
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	button_state m_currentFrame = MOUSE_OUT;
public:
	MenuButton(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

