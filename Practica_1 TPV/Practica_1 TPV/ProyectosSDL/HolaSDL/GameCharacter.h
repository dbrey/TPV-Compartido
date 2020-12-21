#pragma once

#include "GameObject.h"
#include "Texture.h"
#include <list>
using namespace std;

class GameCharacter : public GameObject
{
protected:
	Point2D iniPoint;
	Vector2D dir_actual = Vector2D(1,0);
	Texture* textura;
	// Coord del frame de la textura
	// Iterador a la posicion del objeto dentro de la lista de GameObject
	list<GameCharacter*>::iterator it;

	GameCharacter(Point2D inipos, Vector2D d, Texture* t, Game* g, int largo, int ancho) : GameObject(inipos, ancho, largo, g), iniPoint(inipos), dir_actual(d), textura(t) {}

public:


	void setItList(list<GameCharacter*>::iterator i) { it = i; }
	virtual void saveToFil(ofstream& fil) = 0;
	void Move(Point2D& pos, Vector2D dir, SDL_Rect mapRect);
	virtual void render();
	virtual void update() = 0;
	virtual SDL_Rect getDestRect();
};