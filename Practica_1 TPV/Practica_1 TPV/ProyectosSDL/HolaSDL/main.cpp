// David Brey Plaza
// Pablo Gonzalez Alvarez
// Grupo 2

#include "SDL.h"
#include "SDL_image.h"
#include "PacManError.h"
#include <iostream>
#include "Game.h"
#include "checkML.h"
#include "SDLError.h"

using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	// Variables declaradas
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

	Game game = Game();
	game.run();
	return 0;
}