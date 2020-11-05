
#include "GameMap.h"
#include "Game.h"



// Constructora
GameMap::GameMap(int c, int f, Texture* tM, Texture* tC, Texture* tV)
{
	tMuro = tM;
	tComida = tC;
	tVitamin = tV;
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

				SDL_Rect rect;
				rect.x = i*10;
				rect.y = j*10;
				rect.w = 10;
				rect.h = 10;

				tMuro->render(rect);
			}
		}
	}
}