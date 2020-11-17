#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include <array>
class Game;


class Ghost
{

private:
	Point2D iniPoint;
	Point2D point;
	Vector2D direc;
	Texture* tfantasmas;

	Game *game;

	array<bool, 4> mov; //  0 = left   1 = up    2 = right    3 = down
	

public:
	Ghost(int x, int y, Game* g);

	Point2D getPoint() { return point; }
	void CheckMov();
	void SelecMov();
	void update();
	void morir();
	void render(int aux);

	~Ghost();
};