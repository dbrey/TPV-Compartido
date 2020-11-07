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

	GameMap(int c, int f, Game* g);


	MapCell readCell(int col, int fil)const { return Mapa[fil][col]; };
	void writeCell(int col, int fil, MapCell estado) { Mapa[fil][col] = estado; };

	void render();


};