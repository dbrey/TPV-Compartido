#include "GameMap.h"
#include "Game.h"

// Constructora
GameMap::GameMap(int c, int f)
{

	cols = c;
	fils = f;
	Mapa = new MapCell* [cols];

	for (int i = 0; i < cols; i++)
	{
		Mapa[i] = new MapCell [fils];
	}
}

void GameMap::render() {
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			if (Mapa[i][j] == Wall) {

				SDL_Rect destRect;
				destRect.x = i*10;
				destRect.y = j*10;
				destRect.w = 10;
				destRect.h = 10;

				game->getTexture(Wall)->render(destRect);
			}
			else if (Mapa[i][j] == Vitamins)
			{
				SDL_Rect destRect;
				destRect.x = i * 10;
				destRect.y = j * 10;
				destRect.w = 10;
				destRect.h = 10;

				game->getTexture(Vitamins)->render(destRect);
			}
			else if (Mapa[i][j] == Food)
			{
				SDL_Rect destRect;
				destRect.x = i * 10;
				destRect.y = j * 10;
				destRect.w = 10;
				destRect.h = 10;

				game->getTexture(Food)->render(destRect);
			}
		}
	}
}