#pragma once

#include "Texture.h"
class Game;

enum MapCell { Empty, Wall, Food, Vitamins };
class GameMap
{
	friend class Game; 
private:
	MapCell **Mapa;
	int cols, fils;

	Game* game;

public:

	GameMap(int c, int f, Game* g);


	MapCell readCell(int fil, int col)const { return Mapa[fil][col]; };
	void writeCell(int fil, int col, MapCell estado) { Mapa[fil][col] = estado; };
	SDL_Point mapCoordsToSDLPoint(Point2D& p);
	Point2D SDLPointToMapCoords(SDL_Point& Sp);
	bool intersectsWall(const SDL_Rect& rect);
	void render();

	~GameMap();
};