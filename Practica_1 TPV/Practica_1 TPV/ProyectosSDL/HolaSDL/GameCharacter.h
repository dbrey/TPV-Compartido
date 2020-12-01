#pragma once

#include "GameObject.h"

class GameCharacter : public GameObject
{
private:
	Point2D iniPoint;
	Vector2D dir;
	Texture* textura;
	// Coord del frame de la textura
	// Iterador a la posicion del objeto dentro de la lista de GameObject

public:
	// Constructora para todos los parametros menos el iterador
	// Llamar setItList para el iterador (hay que crear dicho metodo)

	// Metodos render y savetofile (Metodos que tienen en comun Pacman y Ghost)
};