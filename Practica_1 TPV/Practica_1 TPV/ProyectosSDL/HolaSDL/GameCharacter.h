#pragma once
#include "GameObject.h"
#include <list>
#include "checkML.h"

class PlayState; 

using namespace std;

class GameCharacter : public GameObject
{
protected:
	Point2D iniPoint;
	Vector2D dir_actual = Vector2D(1,0);
	Texture* textura;
	int nAnimacion = 0;

	// Coord del frame de la textura
	// Iterador a la posicion del objeto dentro de la lista de GameObject
	list<GameObject*>::iterator it;

	PlayState* play;
	GameCharacter(Point2D inipos, Vector2D d, Texture* t, Game* g, PlayState* pl, int largo, int ancho) : GameObject(inipos, ancho, largo, g), iniPoint(inipos), dir_actual(d), textura(t),play(pl){}

public:


	void setItList(list<GameObject*>::iterator i) { it = i; }
	virtual void saveToFil(ofstream& fil) = 0;
	void Move(Point2D& pos, Vector2D dir, SDL_Rect mapRect);
	void panickGhost(SDL_Rect rect);
	virtual SDL_Rect getDestRect();
	virtual ~GameCharacter() {};
};