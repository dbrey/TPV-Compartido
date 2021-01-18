#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "Game.h" // Se necesita?? Hay mas errores si se usa, pero si se tiene GameState-->include GameObject --> class Game


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
	static void regresarMenu(Game* game);
	static void reiniciar(Game* game);
};

