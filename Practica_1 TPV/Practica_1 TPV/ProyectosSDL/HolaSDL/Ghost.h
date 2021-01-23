#pragma once
#include "GameCharacter.h"
#include "checkML.h"
#include <array>

class Ghost : public GameCharacter
{

protected:
	array<bool, 4> mov; //  0 = left   1 = up    2 = right    3 = down
	int CambMove = 0;
	int nFantasma;
public:
	Ghost(int x, int y, Game* g, PlayState* pl, Vector2D dir, int ancho, int largo, int nF);

	void CheckMov();
	void SelecMov();
	void update();
	void morir();
	void render();
	void saveToFil(ofstream& fil);
	virtual ~Ghost() {};
};