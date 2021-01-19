#include "MainMenuState.h"
#include "Game.h"
#include "GameStateMachine.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	Point2D p1 = Point2D(300, 50);
	Point2D p2 = Point2D(300, 250);
	Point2D p3 = Point2D(300, 450);

	int w1 = 200;
	int h1 = 100;

	jugar = new MenuButton(p1, w1, h1, g, game->getTexture(5), empezar);
	salir = new MenuButton(p2, w1, h1, g, game->getTexture(4), cerrar);
	cargar = new MenuButton(p3, w1, h1, g, game->getTexture(7), loadPartida);

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

}

void MainMenuState::loadPartida(Game* game)
{
	int eleccion;

	cout << "Quieres cargar la partida 1, 2 o 3? ";
	cin >> eleccion;
	stringstream nombre;

	if (eleccion == 1)
	{
		nombre << "../mapas/partida.txt";
	}
	else if (eleccion == 2)
	{
		nombre << "../mapas/partida2.txt";
	}
	else if (eleccion == 3)
	{
		nombre << "../mapas/partida3.txt";
	}
	else
	{
	//	throw FileFormatError();
	}

	PlayState* cargarPartida = new PlayState(game, nombre.str());

	game->stMachine()->pushState(cargarPartida);
}

void MainMenuState::empezar(Game* game)
{
	PlayState* partidaNueva = new PlayState(game);

	game->stMachine()->pushState(partidaNueva);
	//Crear un estado PlayState, pushearlo en stMachine y cambiar a ese estado
}

void MainMenuState::cerrar(Game* game)
{
	game->terminar();
}


MainMenuState::~MainMenuState()
{
	delete jugar;
	delete salir;
	delete cargar;
}