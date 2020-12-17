#pragma once

#include "GameObject.h"
#include "Texture.h"
#include <list>
using namespace std;

class GameCharacter : public GameObject
{
protected:
	Point2D iniPoint;
	Vector2D dir_actual;
	Texture* textura;
	// Coord del frame de la textura
	// Iterador a la posicion del objeto dentro de la lista de GameObject
	list<GameCharacter*>::iterator it; 

public:

	GameCharacter(Point2D inipos, Vector2D d, Texture* t, Game* g) : GameObject(inipos, 21, 27, g), iniPoint(inipos), dir_actual(d), textura(t) {}

	void setItList(list<GameCharacter*>::iterator i) { it = i; }
	virtual void saveToFil(ofstream& fil);

	virtual void render();
	virtual void update() = 0;
	virtual SDL_Rect getDestRect();
};