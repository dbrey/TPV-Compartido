#pragma once

#include "Texture.h"
#include "Vector2D.h"
class Game;

enum MapCell { Empty, Wall, Food, Vitamins };
class GameMap
{
	friend class Game; 
private:
	MapCell **Mapa;
	int cols, fils;
	int windowW = 800;
	int windowH = 600;

	Game* game;

public:

	GameMap(int c, int f, Game* g);


	MapCell readCell(int fil, int col)const { return Mapa[fil][col]; };
	void writeCell(int fil, int col, MapCell estado) { Mapa[fil][col] = estado; };
	SDL_Point mapCoordsToSDLPoint(Point2D& coords);
	Point2D SDLPointToMapCoords(int x, int y);
	bool intersectsWall(const SDL_Rect& rect);
	//void getTamMap(int& x, int& y) { x = cols, y = fils; }
	SDL_Rect getDestRect();
	void render();

	~GameMap();
};