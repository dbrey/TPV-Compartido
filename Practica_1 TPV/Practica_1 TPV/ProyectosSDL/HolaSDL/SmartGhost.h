#pragma once
#include "Ghost.h"
#include<vector>

class SmartGhost : public Ghost
{
private:
	int edad = 0;
public:
	SmartGhost(int x, int y, Game* g, Vector2D dir) : Ghost(x,y,g,dir) {

	}

	void update();

	void Mueve();
};

