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
private:
	Texture* textura;

protected:
	CallBackOnClick* cboq;
public:
	MenuButton(Point2D p, int w1, int h1, Game* g, PlayState* pl, Texture* t) : GameObject(p, w1, h1, g, pl) { textura = t; };
	virtual void clean();
	void update();
	void render();
	SDL_Rect getDestRect();
	bool handleEvent(SDL_Event& event);
};

