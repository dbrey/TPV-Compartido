#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include "PlayState.h"

class MainMenuState: public GameState
{
public:

	MainMenuState(Game* game);
	void update(); 
	static void loadPartida(Game* game);
	static void cerrar(Game* game);
	static void empezar(Game* game);

};

