#include "GameMap.h"
#include "Game.h"

// Constructora
GameMap::GameMap(int c, int f, Game* g)
{

	cols = c;
	fils = f;
	Mapa = new MapCell* [cols];
	game = g;

	for (int i = 0; i < cols; i++)
	{
		Mapa[i] = new MapCell [fils];
	}
}

void GameMap::render() {
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			SDL_Rect destRect;
			destRect.x = i * 10;
			destRect.y = j * 10;
			destRect.w = 10;
			destRect.h = 10;

			if (Mapa[i][j] == Wall) {
				game->getTexture(wall)->render(destRect);
			}
			else if (Mapa[i][j] == Vitamins) {
				game->getTexture(burguer)->render(destRect);
			}
			else if (Mapa[i][j] == Food) {
				game->getTexture(food)->render(destRect);
			}
		}
	}
}