#include "Game.h"

using namespace std;


Game::Game() {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;

	// Inicializacion del SLD, ventana, renderer y otros
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	window_ = window;
	renderer_ = renderer;

	// Ejecucion del metodo
	if (window == nullptr || renderer == nullptr) throw SDLError(SDL_GetError());
	IniTextures();

	stateMachine = new GameStateMachine();
	MainMenuState* menu = new MainMenuState(this);
	stateMachine->pushState(menu);	
}

// Renderizamos todo lo del estado correspondiente
void Game::render() {
	SDL_RenderClear(renderer_);
	
	stateMachine->currentState()->render();

	SDL_RenderPresent(renderer_);
}

// Actualizamos todos los objetos y eventos del estado correspondiente
void Game::run() {
	SDL_Event event;
	while (!fin())
	{
		render();
		stateMachine->currentState()->update();
		if (SDL_PollEvent(&event) != 0)
		{
			stateMachine->currentState()->handleEventos(event);
		}
	}
}

// Inicializamos las texturas
void Game::IniTextures()
{
	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		textures[i] = new Texture(renderer_, TEXTURE_ATRIBS[i].fileName, TEXTURE_ATRIBS[i].numRows, TEXTURE_ATRIBS[i].numCols);
		if(textures[i] == NULL) throw FileNotFoundError("de nombre" + TEXTURE_ATRIBS[i].fileName);
	}	
}


Game::~Game()
{
	// Borramos la maquina de estados, las texturas una a una y destruimos el renderer y la ventana
	delete stateMachine;

	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		delete textures[i];
	}

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}