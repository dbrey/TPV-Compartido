#pragma once

class GameMap
{
	enum MapCell { Empty, Wall, Food, Vitamins };
private:
	MapCell **Mapa;
	int cols, fils;

public:

	GameMap(int c, int f);

	MapCell ReadCell(int col, int fil)const { return Mapa[col][fil]; };
	void WriteCell(int col, int fil, MapCell estado) { Mapa[col][fil] = estado; };

};