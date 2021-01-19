#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include "PlayState.h"

class MainMenuState: public GameState
{
private:
	MenuButton* jugar;
	MenuButton* salir;
	MenuButton* cargar;
public:

	MainMenuState(Game* game);
	void update(); 
	static void loadPartida(Game* game);
	static void cerrar(Game* game);
	static void empezar(Game* game);

};

