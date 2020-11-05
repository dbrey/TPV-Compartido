#pragma once

#include "Vector2D.h"
#include "Texture.h"
class Game;

class PacMan
{
private:

	int vidas = 3;
	int energia;

	Point2D point;
	Vector2D dir;
	Texture* pac;
	// Puntero a Game
public:
	PacMan(Texture* tTexture) {  , pac = tTexture; }

	void HandleEvent(SDL_Event* tecla);
	void Render();
	void Actualizar();
};