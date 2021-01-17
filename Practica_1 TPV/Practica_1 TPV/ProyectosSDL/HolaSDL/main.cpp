// David Brey Plaza
// Pablo Gonzalez Alvarez
// Grupo 2

#include "SDL.h"
#include "SDL_image.h"
#include "PacManError.h"
#include <iostream>
#include "Game.h"

using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	// Variables declaradas
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;


	// Inicializacion del SLD, ventana, renderer y otros
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	// Ejecucion del metodo
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else
	{
		// Coge cualquier error aparte de otro tipo de errores (Ej: carga de texturas)
		try 
		{
			Game game = Game(window, renderer);
			game.run();
		}
		catch(PacManError& e)
		{
			cout << e.what();
		}
	}

	return 0;
}