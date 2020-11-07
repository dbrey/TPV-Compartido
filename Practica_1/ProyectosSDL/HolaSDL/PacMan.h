#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameMap.h"
class Game;

class PacMan
{
private:

	int vidas = 3;
	int energia;

	Point2D point;
	Point2D iniPoint;
	Vector2D dir;
	Game* game;
	Texture* textura;

public:
	
	PacMan(int x, int y, Game* g);

	void handleEvent(SDL_Event tecla);
	void render();
	void actualizar();
};