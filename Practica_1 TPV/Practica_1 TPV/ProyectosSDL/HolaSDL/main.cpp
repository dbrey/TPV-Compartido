// David Brey Plaza
// Pablo Gonzalez Alvarez
// Grupo 2


//La basura que marca en las lineas 13, 9 de gamemap y 90 de playstate corresponde a basura de la practica que no supimos borrar
//y que enla tutoria del lunes nos dijiste que comentasemos para que lo supieses a la hora de corregir el examen


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