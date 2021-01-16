#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"

class MainMenuState: public GameState
{
private:
	list<MenuButton*> m_gameObjects; // Guardamos nuestros objetos del menu

	MenuButton* jugar;
	MenuButton* salir;
	MenuButton* cargar;
public:

	MainMenuState(Game* game);
	void update(); // Cambiar nombre
	virtual void render();


	void OnEnter();
	void OnExit();
};

