#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameMap.h"
#include "GameCharacter.h"
#include "EventHandler.h"
class Game;

class PacMan : public GameCharacter, public EventHandler
{
private:
	const uint32_t  duracion = 1000;

	uint32_t  tiempoforce = 0;

	

	Vector2D dir_sel;

public:
	
	PacMan(int x, int y, Game* g, PlayState* pl, Vector2D dir, int ancho, int largo);
	PacMan(int ancho, int largo, Game* g, PlayState* pl,  ifstream& input);
	
	bool invencible() { return tiempoforce>0; }
	void comida();
	bool handleEvent(SDL_Event& tecla);
	bool handleEvent();
	void render();
	void update();
	void morir();
	void saveToFil(ofstream& fil);
	uint32_t tiempo() { return tiempoforce; }

	~PacMan();
};