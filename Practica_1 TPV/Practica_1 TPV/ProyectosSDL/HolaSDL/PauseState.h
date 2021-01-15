#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "Game.h"
#include "checkML.h"

class PauseState: public GameState
{
private:
	MenuButton* restart;
	MenuButton* salir;
	MenuButton* volver;
public:
	PauseState(Game* game);
	void update();
	static void resume(Game* game);
};

