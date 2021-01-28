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
	MenuButton* panelFinal;
public:
	EndState(Game* game , bool v);
	static void regresarMenu(Game* game);
	static void Exit(Game* game);
	static void Vacio(Game* game) {};
};


