
#include "GameMap.h"


GameMap::GameMap(int cols, int fils)
{
	Mapa = new MapCell* [cols];

	for (int i = 0; i < cols; i++)
	{
		Mapa[i] = new MapCell [fils];
	}
}