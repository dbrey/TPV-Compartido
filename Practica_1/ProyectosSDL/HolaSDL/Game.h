#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"
#include <array>

const int NUM_TEXTURES = 9;

const enum textureName { burguer, characters, food, wall};

struct TextureAtribs
{
	textureName tipo;
	string fileName;
	int numRows, numCols;
};

const TextureAtribs TEXTURE_ATRIBS[NUM_TEXTURES] =
{ { burguer, "burguer1.png",1,1 }, { food, "food2.png", 1,1 }, { wall, "wall3.png", 1,1 }, { characters, "characters1.png", 4, 14 } };


class Game
{
private:

	int VentX, VentY, tamCellX, tamCellY;
	int comida = 0;
	bool exit = false;

	//PacMan* pacman;
	PacMan* pac;
	GameMap* mapa;

	//Ghost* fantasmas[4];
	Ghost* fantasmas[4];

	SDL_Window* window_;
	SDL_Renderer* renderer_;

	array<Texture*,NUM_TEXTURES> textures;
	//Texture* muro;
	

public:

	Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty);

	Texture* getTexture(int i) { return textures[i]; }

	Point2D getPos(int i, int j);

	bool LeeArchivo(string archivo);

	void render() { mapa->render(); }

	void Inicializa();


};