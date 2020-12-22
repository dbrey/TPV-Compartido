#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameMap.h"
#include "GameCharacter.h"
class Game;

class PacMan : public GameCharacter
{
private:
	const uint32_t  duracion = 1000;

	uint32_t  tiempoforce = 0;

	

	Vector2D dir_sel;

public:
	
	PacMan(int x, int y, Game* g, Vector2D dir, int ancho, int largo);
	
	bool invencible() { return tiempoforce>0; }
	void comida();
	void handleEvent(SDL_Event& tecla);
	void render();
	void update();
	void morir();
	void saveToFil(ofstream& fil);
	uint32_t tiempo() { return tiempoforce; }

	~PacMan();
};