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

	GameCharacter(Point2D inipos, Vector2D d, Texture* t, Game* g) : GameObject(inipos, 10, 10, g), iniPoint(inipos), dir_actual(d), textura(t) {

	}
		// Constructora para todos los parametros menos el iterador

	void setItList(List<GameCharacter>::Iterator i) {
		it = i;
	}
	// Llamar setItList para el iterador (hay que crear dicho metodo)

	virtual void render();
	virtual void update() = 0;
	virtual SDL_Rect getDestRect();
	//void saveToFile();
	// Metodos render y savetofile (Metodos que tienen en comun Pacman y Ghost)
};