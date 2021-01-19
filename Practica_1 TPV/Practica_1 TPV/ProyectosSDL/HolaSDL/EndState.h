#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "Game.h" 
#include "checkML.h"

class EndState : public GameState
{
private:
	MenuButton* salir;
	MenuButton* menu;
	bool victoria;
public:
	EndState(Game* game);
	static void regresarMenu(Game* game);
	static void Exit(Game* game) { game->terminar(); };
};

