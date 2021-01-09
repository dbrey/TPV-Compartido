#pragma once
#include "Game.h"

class GameState
{
protected:
	list<GameObject*> stage;
	list<EventHandler*> eventos;
	Game* g;

public:

	GameState(Game* game)
	{
		g = game;
		// Asignar numero de objetos con eventos al event handler
	}

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
	
	void handleEventos()
	{
		for (EventHandler* e : eventos) { if(e->handleEvent()) return; }
	}

	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
};

