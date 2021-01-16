#pragma once

#include "checkML.h"
#include "EventHandler.h"
#include <list> // Necesario? Al tener GameObject-->class Game --> list no deberia serlo, pero quitarlo da muchos errores
#include "GameObject.h"


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

		// Cada estado tiene que manejar sus eventos correspondientes, los cuales mete en manejadores
	}

	~GameState() 
	{
		for (GameObject* o : stage) { delete o; }
	}

	virtual void update() 
	{ 
		for (GameObject* o : stage) { o->update(); }
	}

	void render()
	{
		for (GameObject* o : stage)	{ o->render(); }
	}
	
	void handleEventos(SDL_Event& event)
	{
		for (EventHandler* e : manejadores) { if(e->handleEvent(event)) return; }
	}

	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
};

