#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"

class PauseState: public GameState, public EventHandler
{
public:
	PauseState();
	void update2();
	static void resume(Game* game);
};

