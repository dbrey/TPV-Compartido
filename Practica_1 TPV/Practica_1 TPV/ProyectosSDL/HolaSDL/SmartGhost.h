#pragma once
#include "Ghost.h"
#include <vector>

class PlayState; //?

class SmartGhost : public Ghost
{
private:
	int edad = 1000;
	int edadrip = 3000;
	int edadout = 3500;
	int cuarentena = 1999;

public:
	SmartGhost(int x, int y, Game* g, PlayState* pl, Vector2D dir,int ancho ,int largo, bool bebe) : Ghost(x,y,g,pl,dir,ancho,largo) {
		if (bebe)
		{
			edad = 0;
		}
	}

	void update();
	void render();
	void Mueve();
	bool EsHijo(){	return (edad < 1000);}
	void Movimiento();

	virtual ~SmartGhost() {};
};

