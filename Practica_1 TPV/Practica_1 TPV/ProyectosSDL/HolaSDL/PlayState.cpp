#include "PlayState.h"


void PlayState::update()
{
	// Adaptar el metodo CambioMapa para que lo haga el update de PlayState

	GameState::update();

	for (auto it : objectstoErase)
	{
		delete* it;
		objects.erase(it);
	}
	objectstoErase.clear();

	if (comida == 0)
	{
		nMapa++;
		CambioMapa();

	}

	SDL_Delay(10);
}