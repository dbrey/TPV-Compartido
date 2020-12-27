#pragma once
#include "GameState.h"
#include "MenuButton.h"

class PauseState: public GameState
{
public:
	PauseState();
	bool handleEvent(SDL_Event event);
};

