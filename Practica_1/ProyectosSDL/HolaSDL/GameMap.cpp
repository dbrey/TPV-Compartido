
#include "GameMap.h"


GameMap::GameMap(int c, int f, Texture* textura)
{
	texturaMuro = textura;
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

				texturaMuro->render(rect);
			}
		}
	}
}