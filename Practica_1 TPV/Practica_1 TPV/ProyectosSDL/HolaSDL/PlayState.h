#pragma once
#include "Game.h"
#include "GameState.h"

class PlayState : public GameState
{
private:
	int comida = 0;
	int nMapa = 1;

	int vidas = 3;
	int puntuacion = 0;

	PacMan* pac;
	GameMap* mapa;
	list<Ghost*> ghosts;
	list<list<GameObject*>::iterator> objectstoErase;


public:
	void update();
};

