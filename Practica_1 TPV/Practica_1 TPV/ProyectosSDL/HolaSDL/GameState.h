#pragma once

#include "EventHandler.h"
#include <list> // Necesario? Al tener GameObject-->class Game --> list no deberia serlo, pero quitarlo da muchos errores
#include "GameObject.h"
#include "SDL.h"
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
	}

	~GameState() 
	{
		for (GameObject* o : stage) { delete o; }
	}

	virtual void update() 
	{ 
		for (GameObject* o : stage) 
		{
			o->update(); 
		}
		SDL_Delay(10);
	}

	void render()
	{
		for (GameObject* o : stage)	{ o->render(); }
	}
	
	void handleEventos(SDL_Event& event)
	{
		for (EventHandler* e : manejadores) 
		{ 
			if(e->handleEvent(event)) return;
		}
	}
};

