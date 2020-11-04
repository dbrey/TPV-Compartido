#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"

const int NUM_TEXTURES = 10;
const enum TextureName { PacManT, MuroT, GhostT, FoodT, BurguerT };

class Game
{
private:

	int VentX, VentY, tamCellX, tamCellY;
	int comida = 0;
	bool exit;
	//PacMan* pacman;
	GameMap* mapa;
	//Ghost* fantasmas[4];

	SDL_Window* window_;
	SDL_Renderer* renderer_;

	//Texture texturas[NUM_TEXTURES];
	Texture* muro;
	

public:

	Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty, PacMan* p, GameMap* m);

	bool LeeArchivo(string archivo);

	void render() { mapa->render(); }
};