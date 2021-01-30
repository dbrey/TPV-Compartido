#pragma once

#include "GameObject.h"
#include "checkML.h"

enum MapCell { Empty, Wall, Food, Vitamins };

class GameMap : public GameObject
{
private:
	MapCell **Mapa;
	int cols, fils;
	int windowW = 800;
	int windowH = 600;
public:

	GameMap(int c, int f, Game* g, int x,int y);


	MapCell readCell(int fil, int col)const { return Mapa[fil][col]; };
	void writeCell(int fil, int col, MapCell estado) { Mapa[fil][col] = estado; };
	int c() { return cols; }
	int fil() { return fils; }

	bool intersectsWall(const SDL_Rect& rect, bool g);
	void render();
	void update(); // Metodo para que no de error
	SDL_Rect getDestRect(); // Metodo para que no de error

	Point2D SDLPointToMapCoords(int x, int y);

	~GameMap();
};