#pragma once
#include "Game.h"

class GameState
{
protected:
	list<GameObject*> stage;
	list<EventHandler*> eventos;
	Game* g;

public:

	GameState(Game* g);

	~GameState() 
	{
		for (GameObject* o : stage) { delete o; }
	}

	void update() 
	{ 
		for (GameObject* o : stage) { o->update(); }
	}

	void render()
	{
		for (GameObject* o : stage)	{ o->render(); }
	}
	
	void handleEvent(SDL_Event event)
	{
		for (EventHandler* e : eventos) { if(e->handleEvent(event)) return; }
	}

};

