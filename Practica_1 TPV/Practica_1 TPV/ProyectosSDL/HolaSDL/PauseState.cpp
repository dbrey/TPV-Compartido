#include "PauseState.h"
#include "checkML.h"


PauseState::PauseState(Game* game) : GameState(game)
{
	// Creamos los botones y los añadimos a la lista de objetos y manejadores
	Point2D p1 = Point2D(300, 50);
	Point2D p2 = Point2D(300, 250);
	Point2D p3 = Point2D(300, 450);
	int w1 = 200;
	int h1 = 100;

	MenuButton* guardar = new MenuButton(p1, w1, h1, g, game->getTexture(7), Save);
	MenuButton* continuar = new MenuButton(p2, w1, h1, g, game->getTexture(8), resume);
	MenuButton* volver = new MenuButton(p3, w1, h1, g, game->getTexture(man), regresarMenu);

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

// Terminamos el juego
void PauseState::Exit(Game* game)
{
	game->terminar();
}

// Guardamos la partida
void PauseState::Save(Game* game)
{
	game->stMachine()->popState();


	// 






	dynamic_cast<PlayState*>(game->stMachine()->currentState())->SaveToFile();
}

// Volvemos al estado anterior, continuando la partida
void PauseState::resume(Game* game)
{
	game->stMachine()->popState();
}

// Vamos a un menu nuevo
void PauseState::regresarMenu(Game* game)
{
	MainMenuState* menu = new MainMenuState(game);
	game->stMachine()->pushState(menu);
}
