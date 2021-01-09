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
	bool exit = false;

	GameStateMachine* stateMachine;
	
	
	//PlayState* play;
	
	
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	array<Texture*,NUM_TEXTURES> textures;	

public:

	Game(SDL_Window* window, SDL_Renderer* renderer);

	Texture* getTexture(int i) { return textures[i]; }

	void render();
	
	bool fin() { return exit; }

	void IniTextures();

	void run();

	GameStateMachine* stMachine() { return stateMachine; }

	void terminar(bool ex) { exit = ex; }

	SDL_Renderer* getRenderer() { return renderer_; }

	GameStateMachine* stMachine() { return stateMachine; }
	bool ex(bool e) { exit = e; }


	//SDL_Point mapCoordsToSDLPoint(Point2D& coords);
	//Point2D SDLPointToMapCoords(int x, int y);

	//bool LeeArchivo(string archivo);


	//bool trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos, bool g);

	//void check();

	//void update();

	//void CambioMapa();

	//void ripFantasma(SmartGhost* Sg);

	//string nombreNivel(int nMapa);

	//bool Hijo(SmartGhost* Sg);
	//bool ComprobarDistancia(SmartGhost* Sg, list<SmartGhost*>::iterator it);



	//void SaveToFile();
	//bool Chocar(SDL_Rect Sg1, SDL_Rect Sg2);

	//void eraseGhost(list<GameObject*>::iterator it);
	//void eraseObject(list<GameObject*>::iterator it);

	~Game();
};