#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	Point2D p1 = Point2D(300, 200);
	Point2D p2 = Point2D(300, 600);
	int w1 = 200;
	int h1 = 100;

	jugar = new MenuButton(p1, w1, h1, g, game->getTexture(5), empezar);
	salir = new MenuButton(p1, w1, h1, g, game->getTexture(4), cerrar);
	cargar = new MenuButton(p1, w1, h1, g, game->getTexture(7), loadPartida);

	stage.push_back(jugar);
	stage.push_back(salir);
	stage.push_back(cargar);

	manejadores.push_back(jugar);
	manejadores.push_back(salir);
	manejadores.push_back(cargar);

	g->stMachine()->pushState(this);
}

void MainMenuState::update()
{
	// Revisamos los handleEvent de todos los posibles eventos
	SDL_Event event;
	if (SDL_PollEvent(&event) != 0)
	{
		handleEventos(event);
	}
}

void MainMenuState::loadPartida(Game* game)
{
	// Llamar de alguna forma al LeeArchivo de PlayState y meterle el archivo a abrir como referencia
}

void MainMenuState::empezar(Game* game)
{
	// game->stMachine->changeState();

	// Crear un estado PlayState, pushearlo en stMachine y cambiar a ese estado
}

void MainMenuState::cerrar(Game* game)
{
	game->terminar(true);
}

void MainMenuState::OnEnter(){}
