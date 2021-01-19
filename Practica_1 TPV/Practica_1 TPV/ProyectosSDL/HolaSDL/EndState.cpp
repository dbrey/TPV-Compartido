#include "EndState.h"
#include "GameStateMachine.h"
#include "checkML.h"


EndState::EndState(Game* game, bool v) : GameState(game)
{
	// Creamos los botones y los añadimos a la lista de objetos y manejadores
	Point2D p1 = Point2D(150, 300);
	Point2D p2 = Point2D(450, 300);
	Point2D p3 = Point2D(350, 100);
	int w1 = 200;
	int h1 = 100;

	salir = new MenuButton(p1, w1, h1, g, game->getTexture(4), Exit);
	menu = new MenuButton(p2, w1, h1, g, game->getTexture(5), regresarMenu);

	stage.push_back(menu);
	stage.push_back(salir);

	manejadores.push_back(menu);
	manejadores.push_back(salir);

	// Dependiendo de si ha ganado o no, aparecera un panel u otro
	if (v)
	{
		panelFinal = new MenuButton(p3, w1, h1, g, game->getTexture(9), Vacio);
	}
	else
	{
		panelFinal = new MenuButton(p3, w1, h1, g, game->getTexture(10), Vacio);
	}

	stage.push_back(panelFinal);
	manejadores.push_back(panelFinal);
}

// Terminamos el juego
void EndState::Exit(Game* game)
{
	game->terminar();
}

// Regresa a un nuevo menu
void EndState::regresarMenu(Game* game)
{
	MainMenuState* menu = new MainMenuState(game);
	game->stMachine()->pushState(menu);
}


EndState::~EndState()
{
	GameState::~GameState();

	delete[] panelFinal;
	delete[] salir;
	delete[] menu;
}