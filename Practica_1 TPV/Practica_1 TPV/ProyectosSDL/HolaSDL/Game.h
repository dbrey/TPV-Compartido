#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"
#include "GameObject.h"
#include "SmartGhost.h"
#include <array>
#include <list>
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

	list<Ghost*> fantasmas;
	list<GameObject*> objects;
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	array<Texture*,NUM_TEXTURES> textures;	

public:

	Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty);

	Texture* getTexture(int i) { return textures[i]; }

	int CellX() { return tamCellX; }
	int CellY() { return tamCellY; }

	bool LeeArchivo(string archivo);

	void render();

	bool fin() { return exit; }

	void IniTextures();

	GameMap* getMapa() { return mapa; }
	PacMan* getPac() {return pac; }
	Ghost* getGhost(int i);

	SDL_Rect map(){ return mapa->getDestRect(); }

	SDL_Point mapCoordsToSDLPoint(Point2D& coords);
	Point2D SDLPointToMapCoords(int x, int y);

	void run();

	void handleEvent(SDL_Event& tecla);

	bool trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos);

	void check();

	void update();

	void CambioMapa();

	string nombreNivel(int nMapa);

	//bool Hijo(SmartGhost* Sg);

	void restaComida() { comida--; }

	void SaveToFile();
	bool Chocar(SDL_Rect Sg1, SDL_Rect Sg2);


	~Game();
};