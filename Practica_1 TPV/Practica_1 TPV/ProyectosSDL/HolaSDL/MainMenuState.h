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
	virtual void update();
	virtual void render();
	void s_menuToPlay(); // Pasa al PlayState (en cuanto reciba un click)

};

