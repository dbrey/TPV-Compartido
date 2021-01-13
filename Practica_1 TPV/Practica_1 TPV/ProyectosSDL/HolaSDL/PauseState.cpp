#include "PauseState.h"
#include "checkML.h"

PauseState::PauseState()
{
	new MenuButton boton1();
	stage.push_back(boton1);
	stage.push_back(new MenuButton(...);
	stage.push_back(new MenuButton(...);

	manejadores.push_back(boton1);
}

void PauseState::update2()
{
	update(); // Hacemos update de todos los objetos con update

	SDL_Event event;
	if (SDL_PollEvent(&event) != 0)
	{
		handleEventos(event);
	}
}

void PauseState::resume(Game* game)
{
	game->stMachine()->popState();
}