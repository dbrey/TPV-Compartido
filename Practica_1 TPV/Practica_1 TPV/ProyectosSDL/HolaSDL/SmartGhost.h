#pragma once
#include "Ghost.h"
#include<vector>

class SmartGhost : public Ghost
{
private:
	int edad = 0;
	int cuarentena = 1000;

public:
	SmartGhost(int x, int y, Game* g, Vector2D dir,int ancho ,int largo) : Ghost(x,y,g,dir,ancho,largo) {

	}

	void update();

	void Mueve();
};

