#pragma once

#include "GameCharacter.h"
#include "EventHandler.h"
#include "checkML.h"

class PacMan : public GameCharacter, public EventHandler
{
private:
	const uint32_t  duracion = 1000;
	int nAnimacion = 0;
	uint32_t  tiempoforce = 0;
	Vector2D dir_sel;

public:
	
	PacMan(int x, int y, Game* g, PlayState* pl, Vector2D dir, int ancho, int largo);
	
	bool invencible() { return tiempoforce>0; }
	void comida();
	bool handleEvent(SDL_Event& tecla);
	void render();
	void update();
	void morir();
	void saveToFil(ofstream& fil);
	uint32_t tiempo() { return tiempoforce; }

	~PacMan();
};