#include "EndState.h"
#include "GameStateMachine.h"

EndState::EndState(Game* game) : GameState(game)
{
	Point2D p1 = Point2D(100, 300);
	Point2D p2 = Point2D(400, 300);
	int w1 = 200;
	int h1 = 100;

	salir = new MenuButton(p1, w1, h1, g, game->getTexture(5), Exit);
	menu = new MenuButton(p2, w1, h1, g, game->getTexture(4), regresarMenu);

	stage.push_back(menu);
	stage.push_back(salir);


	manejadores.push_back(menu);
	manejadores.push_back(salir);
}


void EndState::regresarMenu(Game* game)
{
	MainMenuState* menu = new MainMenuState(game);

	game->stMachine()->changeState(menu);
}