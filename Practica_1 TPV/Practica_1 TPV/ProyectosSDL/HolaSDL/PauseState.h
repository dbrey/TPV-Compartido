#pragma once
#include "GameState.h"
#include "MenuButton.h"

class PauseState: public GameState, public EventHandler
{
public:
	PauseState();

	static void resume(Game* game);
};

