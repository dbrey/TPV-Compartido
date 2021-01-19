#include "PauseState.h"

PauseState::PauseState(Game* game) : GameState(game)
{
	Point2D p1 = Point2D(300, 50);
	Point2D p2 = Point2D(300, 250);
	Point2D p3 = Point2D(300, 450);
	int w1 = 200;
	int h1 = 100;

	guardar = new MenuButton(p1, w1, h1, g, game->getTexture(7), Save);
	continuar = new MenuButton(p2, w1, h1, g, game->getTexture(8), resume);
	volver = new MenuButton(p3, w1, h1, g, game->getTexture(man), regresarMenu);

	stage.push_back(guardar);
	stage.push_back(continuar);
	stage.push_back(volver);

	manejadores.push_back(guardar);
	manejadores.push_back(continuar);
	manejadores.push_back(volver);
}

void PauseState::update()
{
	
}

void PauseState::Exit(Game* game)
{
	game->terminar();
}

void PauseState::Save(Game* game)
{
	game->stMachine()->popState();
	// Pedir a game el PlayState

	dynamic_cast<PlayState*>(game->stMachine()->currentState())->SaveToFile();

	
		// Hacer static_cast/dynamic (mejor dynamic) del state
}

void PauseState::resume(Game* game)
{
	game->stMachine()->popState();
}

void PauseState::regresarMenu(Game* game)
{
	MainMenuState* menu = new MainMenuState(game);
	game->stMachine()->pushState(menu);
}
