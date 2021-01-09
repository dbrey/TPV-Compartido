#pragma once
#include "GameObject.h"
#include "EventHandler.h"
#include "Game.h"
#include "PlayState.h"
#include "GameStateMachine.h"

class MenuButton: public GameObject,public EventHandler
{
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	button_state m_currentFrame = MOUSE_OUT;
	GameStateMachine* stMachine;
	EventHandler* eHandler;

public:
	MenuButton(Point2D p, int w1, int h1, Game* g, PlayState* pl, EventHandler* e, GameStateMachine* stMach) : GameObject(p, w1, h1, g, pl) { eHandler = e, stMachine = stMach; }
	virtual void draw();
	virtual void clean();
	bool handleEvent();
};

