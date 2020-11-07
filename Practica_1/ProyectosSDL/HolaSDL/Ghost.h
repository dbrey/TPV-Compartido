#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include <array>
class Game;

class Ghost
{

	enum direction { left, up, right, down };


private:

	Point2D point;
	Vector2D direc;
	//Texture* tfantasmas;
	Game* game;
	GameMap* mapa;

	direction dir;
	array<bool, 4> mov; //  0 = left   1 = up    2 = right    3 = down
	

public:
	//Ghost(int x, int y, Texture* tTexture) { point(x, y); tfantasmas = tTexre; }
	/*for (int i = 0; i < mov.Length; i++) constructora
	{
		mov[i] = true;
	}*/
	
	/*direction CheckMov(GameMap* m);
	direction SelecMov();
	void MovementVerde(GameMap* m)

	void Render();
	void Actualizar();*/
};