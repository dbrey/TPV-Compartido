#include "GameCharacter.h"

void GameCharacter::render() {
	SDL_Rect rect;
	rect.x = point.getX();
	rect.y = point.getY();
	rect.w = w;
	rect.h = h;

	textura->render(rect);
}


SDL_Rect GameCharacter::getDestRect()
{ 
	SDL_Rect aux;
	aux.x = point.getX();
	aux.y = point.getY();

	aux.w = w;
	aux.h = h;
	return aux;
}

void GameCharacter::Move(Point2D& pos, Vector2D dir)
{
	pos.Suma(dir.GetX() * 6, dir.GetY() * 6);
}
