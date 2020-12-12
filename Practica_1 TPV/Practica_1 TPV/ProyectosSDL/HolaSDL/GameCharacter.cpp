#include "GameCharacter.h"

void GameCharacter::render() {
	SDL_Rect rect;
	rect.x = point.getX() * 10;
	rect.y = point.getY() * 10;
	rect.w = h;
	rect.h = w;

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

void GameCharacter::saveToFil(ofstream& fil)
{
	if (pacman)
	{
		fil.
	}
	else if (fantasma)
}