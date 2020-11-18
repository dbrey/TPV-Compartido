#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameMap.h"
class Game;

class PacMan
{
private:
	const uint32_t  duracion = 40;

	uint32_t  tiempoforce = 0;

	int vidas = 3;
	int energia;


	Point2D point;
	Point2D iniPoint;
	Vector2D dir;
	Game* game;
	Texture* textura;

public:
	
	PacMan(int x, int y, Game* g);
	
	Point2D PacP() { return point; }

	int returnLives() { return vidas; }
	void comida();
	void handleEvent(SDL_Event& tecla);
	void render();
	void update();
	void morir();
	void check();
	~PacMan();
};