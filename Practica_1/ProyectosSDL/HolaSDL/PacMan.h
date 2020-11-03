#pragma once

#include "Vector2D.h"
#include "Texture.h"
//#include "Game.h"

class PacMan
{
private:

	int x, y;
	Vector2D dir;
	Texture* tfantasmas;
	// Puntero a Game
public:
	PacMan(int X, int Y, Texture* tTexture) { x = X; y = Y, tfantasmas = tTexture; }
};