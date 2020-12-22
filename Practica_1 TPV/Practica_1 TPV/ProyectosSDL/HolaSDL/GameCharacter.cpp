#include "GameCharacter.h"

void GameCharacter::render() {
	SDL_Rect rect;
	rect.x = point.getX();
	rect.y = point.getY();
	rect.w = w;
	rect.h = h;

	textura->render(rect);
}

//Cogemos el rect del personaje
SDL_Rect GameCharacter::getDestRect()
{ 
	SDL_Rect aux;
	aux.x = point.getX();
	aux.y = point.getY();

	aux.w = w;
	aux.h = h;
	return aux;
}

// Movemos al personaje
void GameCharacter::Move(Point2D& pos, Vector2D dir,SDL_Rect mapRect)
{
	pos.Suma(dir.GetX(), dir.GetY());

	// Comprobamos direccion y averiguamos si nos salimos del mapa
	// Derecha
	if (dir.GetX() > 0 && (pos.getX() + w) >= mapRect.x + mapRect.w)
		pos.SetPos(0, pos.getY());

	//Izquierda
	else if (dir.GetX() < 0 && (pos.getX()) <= 1)
		pos.SetPos(mapRect.w - getDestRect().x - getDestRect().w, pos.getY());

	// Arriba
	else if (dir.GetY() < 0 && (pos.getY()) <= 0)
		pos.SetPos(pos.getX(), mapRect.h - getDestRect().y - getDestRect().h);

	// Abajo
	else if (dir.GetY() > 0 && (pos.getY() + h) > mapRect.y + mapRect.h)
		pos.SetPos(pos.getX(), 0);
}


