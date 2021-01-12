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


void PauseState::resume(Game* game)
{
	game->stMachine()->popState();
}