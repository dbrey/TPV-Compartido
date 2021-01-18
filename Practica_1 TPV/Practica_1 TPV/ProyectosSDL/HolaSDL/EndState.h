#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "Game.h" // Se necesita?? Hay mas errores si se usa, pero si se tiene GameState-->include GameObject --> class Game


class EndState : public GameState
{
private:
	MenuButton* salir;
	MenuButton* menu;
	bool victoria;
public:
	EndState(Game* game);
	void update();
	static void regresarMenu(Game* game);
	static void Exit(Game* game) { game->terminar(); };

	void OnEnter();
	void OnExit() ;
};

