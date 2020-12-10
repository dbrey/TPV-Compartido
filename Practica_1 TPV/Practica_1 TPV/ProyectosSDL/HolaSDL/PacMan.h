#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameMap.h"
#include "GameCharacter.h"
class Game;

class PacMan : public GameCharacter
{
private:
	const uint32_t  duracion = 40;

	uint32_t  tiempoforce = 0;

	int vidas = 90;
	int puntuacion = 0;

	Vector2D dir_sel;

public:
	
	PacMan(int x, int y, Game* g);
	

	int returnLives() { return vidas; }
	void comida();
	void handleEvent(SDL_Event& tecla);
	void render();
	void update();
	void morir();
	void check();

	int puntos() { return puntuacion; }
	~PacMan();
};