#include "PauseState.h"


PauseState::PauseState(Game* game) : GameState(game)
{
	Point2D p1 = Point2D(300, 200);
	Point2D p2 = Point2D(300, 400);
	Point2D p3 = Point2D(300, 600);
	int w1 = 200;
	int h1 = 100;

	restart = new MenuButton(p1, w1, h1, g, game->getTexture(7), reiniciar);
	salir = new MenuButton(p2, w1, h1, g, game->getTexture(4), regresarMenu);
	volver = new MenuButton(p3, w1, h1, g, game->getTexture(8), resume);

	stage.push_back(restart);
	stage.push_back(salir);
	stage.push_back(volver);

	manejadores.push_back(restart);
	manejadores.push_back(salir);
	manejadores.push_back(volver);

	g->stMachine()->pushState(this);
}

void PauseState::update()
{
	update(); // Hacemos update de todos los objetos con update

	// Revisamos los handleEvent de todos los posibles eventos
	SDL_Event event;
	if (SDL_PollEvent(&event) != 0)
	{
		handleEventos(event);
	}
}


void PauseState::resume(Game* game)
{
	game->stMachine()->popState();
}

void PauseState::regresarMenu(Game* game)
{
	//game->stMachine()->changeState();
}

void PauseState::reiniciar(Game* game)
{
	//game->stMachine()->
	// Eliminar el playstate que tenemos si no es nulo, crear un PlayState nuevo, pushearlo a stMachine y finalmente 
	//cambiar a ese estado
}