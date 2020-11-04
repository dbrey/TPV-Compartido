#pragma once

#include "Texture.h"

enum MapCell { Empty, Wall, Food, Vitamins };
class GameMap
{
private:
	MapCell **Mapa;
	int cols, fils;

	Texture* texturaMuro;

public:

	GameMap(int c, int f, Texture* textura);

	MapCell readCell(int col, int fil)const { return Mapa[col][fil]; };
	void writeCell(int col, int fil, MapCell estado) { Mapa[col][fil] = estado; };

	void render();


};