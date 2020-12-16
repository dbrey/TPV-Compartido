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

void GameCharacter::saveToFil(ofstream& fil)
{
	/*if (pacman)
	{
		fil.
	}
	else if (fantasma)*/
}