#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"
#include <array>

const int NUM_TEXTURES = 4;

const enum textureName { burguer, characters, food, wall};

struct TextureAtribs
{
	textureName tipo;
	string fileName;
	uint numRows, numCols;
};

const TextureAtribs TEXTURE_ATRIBS[NUM_TEXTURES] =
{ { burguer, "..\\images\\burguer1.png",1,1 }, { characters, "..\\images\\characters1.png", 4, 14 }, { food, "..\\images\\food2.png", 1,1 }, { wall, "..\\images\\wall3.png", 1,1 } };


class Game
{
private:

	int VentX, VentY, tamCellX, tamCellY;
	int comida = 0;
	bool exit = false;

	PacMan* pac;
	GameMap* mapa;

	array<Ghost*, 4> fantasmas;

	SDL_Window* window_;
	SDL_Renderer* renderer_;

	array<Texture*,NUM_TEXTURES> textures;	

public:

	Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty);

	Texture* getTexture(int i) { return textures[i]; }

	bool LeeArchivo(string archivo);

	void render();

	bool fin() { return exit; }

	void Inicializa();

	GameMap* getMapa() { return mapa; }
	PacMan* getPac() {return pac; }
	Ghost* getGhost(int i) { return fantasmas[i]; }

	void run();

	void handleEvent(SDL_Event& tecla);

	void update();

	bool nextCell(Vector2D dir, Point2D pos);

	~Game();
};