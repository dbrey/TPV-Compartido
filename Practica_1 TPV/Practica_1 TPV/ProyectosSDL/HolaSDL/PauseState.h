#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "Game.h"
#include "checkML.h"

class PauseState: public GameState
{

public:
	PauseState(Game* game);
	void update() {};
	void SaveTooFile() {};
	static void resume(Game* game);
	static void regresarMenu(Game* game);
	static void Save(Game* game);
	static void Exit(Game* game);

};

