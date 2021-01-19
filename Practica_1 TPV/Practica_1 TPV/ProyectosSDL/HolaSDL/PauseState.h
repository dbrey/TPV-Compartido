#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "Game.h" // Se necesita?? Hay mas errores si se usa, pero si se tiene GameState-->include GameObject --> class Game
#include "checkML.h"

class PauseState: public GameState
{
private:
	MenuButton* guardar;
	MenuButton* continuar;
	MenuButton* volver;
public:
	PauseState(Game* game);
	void update();
	void SaveTooFile() {};
	static void resume(Game* game);
	static void regresarMenu(Game* game);
	static void Save(Game* game);
	static void Exit(Game* game);

	~PauseState();
};

