#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	Point2D p1 = Point2D(300, 200);
	Point2D p2 = Point2D(300, 600);
	int w1 = 200;
	int h1 = 100;

	jugar = new MenuButton(p1, w1, h1, g, game->getTexture(5));
	salir = new MenuButton(p1, w1, h1, g, game->getTexture(4));
	cargar = new MenuButton(p1, w1, h1, g, game->getTexture(7));

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

void MainMenuState::render()
{
	list<MenuButton*>::iterator it = m_gameObjects.begin();

	while (it != m_gameObjects.end())
	{
		(*it)->render();
		it++;
	}
}

void MainMenuState::OnEnter(){}
