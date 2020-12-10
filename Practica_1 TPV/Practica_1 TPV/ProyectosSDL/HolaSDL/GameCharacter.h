#pragma once

#include "GameObject.h"
#include "List.h"

class GameCharacter : public GameObject
{
protected:
	Point2D iniPoint;
	Vector2D dir_actual;
	Texture* textura;
	// Coord del frame de la textura
	// Iterador a la posicion del objeto dentro de la lista de GameObject
	List<GameCharacter>::Iterator it;

public:

	GameCharacter(Point2D inipos, Vector2D d, Texture* t, Game* g) : GameObject(inipos, 10, 10, g), iniPoint(inipos), dir_actual(d), textura(t) {}

	void setItList(List<GameCharacter>::Iterator i) { it = i; }
	void savetofile(ifstream fil);

	virtual void render();
	virtual void update() = 0;
	virtual SDL_Rect getDestRect();
};