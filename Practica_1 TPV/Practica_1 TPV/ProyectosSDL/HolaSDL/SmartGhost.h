#pragma once
#include "Ghost.h"
#include<vector>

class SmartGhost : public Ghost
{
private:
	int edad = 1000;
	int edadrip = 3000;
	int edadout = 3500;
	int cuarentena = 1999;

public:
	SmartGhost(int x, int y, Game* g, Vector2D dir,int ancho ,int largo, bool bebe) : Ghost(x,y,g,dir,ancho,largo) {
		if (bebe)
		{
			edad = 0;
		}
	}
	//bool operator =(SmartGhost* Sg1, SmartGhost* Sg2) const { return Sg1 == Sg2; }

	void update();
	void render();
	void Mueve();
	bool EsHijo(){	return (edad < 1000);}
	void Movimiento();

	virtual ~SmartGhost() {};
};

