#pragma once
#include "GameObject.h"
#include "EventHandler.h"
#include "Game.h"
#include "PlayState.h"
#include "GameStateMachine.h"
#include "checkML.h"

using CallBackOnClick = void(Game* game);

class MenuButton: public GameObject,public EventHandler
{
protected:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	button_state m_currentFrame = MOUSE_OUT;
	GameStateMachine* stMachine;
	EventHandler* eHandler;

	CallBackOnClick* cboq;
public:
	MenuButton(Point2D p, int w1, int h1, Game* g, PlayState* pl, EventHandler* e, GameStateMachine* stMach) : GameObject(p, w1, h1, g, pl) { eHandler = e, stMachine = stMach; }
	virtual void draw();
	virtual void clean();
	void 
	bool handleEvent(SDL_Event event);
};

