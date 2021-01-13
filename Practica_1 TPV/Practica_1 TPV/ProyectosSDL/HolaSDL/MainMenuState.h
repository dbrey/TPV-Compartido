#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "checkML.h"
#include <list>

class MainMenuState: public GameState
{
private:
	list<MenuButton*> m_gameObjects; // Guardamos nuestros objetos del menu
public:

	MainMenuState(Game* game) : GameState(game) {};
	void update2(); // Cambiar nombre
	virtual void render();


	void OnEnter();
	void OnExit();
};

