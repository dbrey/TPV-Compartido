#pragma once
#include "GameObject.h"
#include "EventHandler.h"
#include "Game.h"



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
public:
	MenuButton(Point2D p, int w1, int h1, Game* g, PlayState* pl): GameObject( p,  w1,  h1,  g,  pl){}
	virtual void draw();
	virtual bool update();
	virtual void clean();
};

