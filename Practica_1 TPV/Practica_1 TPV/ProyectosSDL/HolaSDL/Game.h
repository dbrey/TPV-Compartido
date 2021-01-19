#pragma once

#include "FileNotFoundError.h"
#include "FileFormatError.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "checkML.h"

#include <array>
#include <list>
using namespace std;
const int NUM_TEXTURES = 11;

const enum textureName { burguer, characters, food, wall, ex, p, man, restart, resume, win, lose};

struct TextureAtribs
{
	textureName tipo;
	string fileName;
	uint numRows, numCols;
};


const TextureAtribs TEXTURE_ATRIBS[NUM_TEXTURES] =
{ { burguer, "..\\images\\burguer1.png",1,1 }, { characters, "..\\images\\characters1.png", 4, 14 }, { food, "..\\images\\food2.png", 1,1 }, { wall, "..\\images\\wall3.png", 1,1 }, { ex, "..\\images\\exit.png",1,3 },
	{ p, "..\\images\\play.png",1,3 }, { man, "..\\images\\main.png",1,3 }, { restart, "..\\images\\restart.png",1,3 },
	{ resume, "..\\images\\resume.png",1,3 }, {win, "..\\images\\victory.png", 1,3}, {lose, "..\\images\\lost.png", 1,3}
};



class Game
{
private:
	bool exit = false;

	GameStateMachine* stateMachine;
	
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

	void terminar() { exit = true; }

	SDL_Renderer* getRenderer() { return renderer_; }

	~Game();
};