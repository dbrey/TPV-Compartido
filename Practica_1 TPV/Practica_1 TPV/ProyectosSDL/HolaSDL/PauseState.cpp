#include "PauseState.h"


PauseState::PauseState()
{
	stage.push_back(new MenuButton(...));
	state.push_back(new MenuButton(...);
	state.push_back(new MenuButton(...);
}

bool PauseState::handleEvent(SDL_Event event)
{
	if () // Pulsa el raton
	{
		//Ejecutar accion 
		return true;
	}
	return false;
}