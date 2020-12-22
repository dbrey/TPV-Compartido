#pragma once

#include "Texture.h"
#include "Vector2D.h"
#include "GameObject.h"
class Game;

enum MapCell { Empty, Wall, Food, Vitamins };
class GameMap : public GameObject
{
	friend class Game; 
private:
	MapCell **Mapa;
	int cols, fils;
	int windowW = 800;
	int windowH = 600;

public:

	GameMap(int c, int f, Game* g);


	MapCell readCell(int fil, int col)const { return Mapa[fil][col]; };
	void writeCell(int fil, int col, MapCell estado) { Mapa[fil][col] = estado; };
	bool intersectsWall(const SDL_Rect& rect, bool g);
	void render();
	void update(); // Metodo para que no de error
	SDL_Rect getDestRect(); // Metodo para que no de error

	~GameMap();
};