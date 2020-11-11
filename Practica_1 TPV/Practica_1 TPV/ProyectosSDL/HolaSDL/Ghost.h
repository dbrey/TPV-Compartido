#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include <array>
class Game;

enum direction { left, up, right, down };

class Ghost
{

private:
	Point2D iniPoint;
	Point2D point;
	Vector2D direc;
	Texture* tfantasmas;
	Game* game;
	//GameMap* mapa;

	direction dir;
	array<bool, 4> mov; //  0 = left   1 = up    2 = right    3 = down
	

public:
	Ghost(int x, int y, Game* g);

	direction CheckMov();
	direction SelecMov();
	void CambiaPos();
	void update();
	void Actualizar();

	void render(int aux);
};