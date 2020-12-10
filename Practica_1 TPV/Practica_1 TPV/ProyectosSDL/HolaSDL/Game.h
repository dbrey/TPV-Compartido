#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"
#include "List.h"
#include "GameObject.h"
#include <array>
using namespace std;
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
	int nMapa = 1;

	PacMan* pac;
	GameMap* mapa;

	List<Ghost*> fantasmas;
	List<GameObject*> objects;
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	array<Texture*,NUM_TEXTURES> textures;	

public:

	Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty);

	Texture* getTexture(int i) { return textures[i]; }

	bool LeeArchivo(string archivo);

	void render();

	bool fin() { return exit; }

	void IniTextures();

	GameMap* getMapa() { return mapa; }
	PacMan* getPac() {return pac; }
	Ghost* getGhost(int i);

	void run();

	void handleEvent(SDL_Event& tecla);

	void update();

	void CambioMapa();

	string nombreNivel(int nMapa);

	bool tryMove(const SDL_Rect rect, Vector2D dir, Point2D& newPos);

	bool nextCell(Vector2D dir, Point2D pos);

	void restaComida() { comida--; }

	void SaveToFile();

	~Game();
};