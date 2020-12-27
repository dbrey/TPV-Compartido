#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"
#include "FileNotFoundError.h"
#include "FileFormatError.h"
#include "GameObject.h"
#include "SmartGhost.h"
#include "GameStateMachine.h"

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

	int vidas = 3;
	int puntuacion = 0;

	PacMan* pac;
	GameMap* mapa;

	list<SmartGhost*> fantasmas;
	GameStateMachine* stateMachine;
	list<list<GameObject*>::iterator> objectstoErase;
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
	
	void restaVida() { vidas--; }
	void sumaPuntos() { puntuacion += 10; }

	bool fin() { return exit; }

	void IniTextures();

	GameMap* getMapa() { return mapa; }
	PacMan* getPac() {return pac; }

	SDL_Rect map(){ return mapa->getDestRect(); }

	SDL_Point mapCoordsToSDLPoint(Point2D& coords);
	Point2D SDLPointToMapCoords(int x, int y);

	void run();

	void handleEvent(SDL_Event& tecla);

	bool trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos, bool g);

	void check();

	void update();

	void CambioMapa();

	void ripFantasma(SmartGhost* Sg);

	string nombreNivel(int nMapa);

	bool Hijo(SmartGhost* Sg);
	bool ComprobarDistancia(SmartGhost* Sg, list<SmartGhost*>::iterator it);

	void restaComida() { comida--; }

	void SaveToFile();
	bool Chocar(SDL_Rect Sg1, SDL_Rect Sg2);

	void eraseGhost(list<GameObject*>::iterator it);
	void eraseObject(list<GameObject*>::iterator it);

	~Game();
};