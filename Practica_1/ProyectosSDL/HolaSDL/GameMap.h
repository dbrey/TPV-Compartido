#pragma once

#include "Texture.h"
class Game;

enum MapCell { Empty, Wall, Food, Vitamins };
class GameMap
{
private:
	MapCell **Mapa;
	int cols, fils;

	Texture* tMuro;
	Texture* tComida;
	Texture* tVitamin;

public:

	GameMap(int c, int f, Texture* tM, Texture* tC, Texture* tV);


	MapCell readCell(int col, int fil)const { return Mapa[col][fil]; };
	void writeCell(int col, int fil, MapCell estado) { Mapa[col][fil] = estado; };

	void render();


};