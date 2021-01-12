#pragma once
#include "Game.h"
#include "checkML.h"

class GameState
{
protected:
	list<GameObject*> stage;
	list<EventHandler*> manejadores;
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
	
	void handleEventos(SDL_Event event)
	{
		for (EventHandler* e : manejadores) { if(e->handleEvent(event)) return; }
	}

	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
};

