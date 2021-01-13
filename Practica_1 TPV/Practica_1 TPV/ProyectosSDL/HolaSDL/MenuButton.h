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
	GameStateMachine* stMachine;
	EventHandler* eHandler;

	CallBackOnClick* cboq;
public:
	MenuButton(Point2D p, int w1, int h1, Game* g, PlayState* pl, EventHandler* e, GameStateMachine* stMach) : GameObject(p, w1, h1, g, pl) { eHandler = e, stMachine = stMach; }
	virtual void draw();
	virtual void clean();
	bool handleEvent(SDL_Event event);
};

