#include "PauseState.h"

PauseState::PauseState()
{
	stage.push_back(new MenuButton(..., resume);
	stage.push_back(new MenuButton(...);
	stage.push_back(new MenuButton(...);
}


void PauseState::resume(Game* game)
{
	game->stMachine()->popState();
}