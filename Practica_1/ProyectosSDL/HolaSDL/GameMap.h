#pragma once

#include "Texture.h"
class Game;

enum MapCell { Empty, Wall, Food, Vitamins };
class GameMap
{
	friend class Game; // ??
private:
	MapCell **Mapa;
	int cols, fils;

	Game* game;

public:

	GameMap(int c, int f);


	MapCell readCell(int col, int fil)const { return Mapa[col][fil]; };
	void writeCell(int col, int fil, MapCell estado) { Mapa[col][fil] = estado; };

	void render();


};