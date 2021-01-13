#include "MainMenuState.h"
#include "checkML.h"

void MainMenuState::update2()
{
	update(); // Hacemos update de todos los objetos con update
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

void MainMenuState::OnEnter()
{
	Point2D p1 = Point2D(300, 200);
	Point2D p2 = Point2D(300, 600);

	int w1 = 200;
	int h1 = 100;

	//de aqui quitar playstate y eventhandler¿?
	MenuButton* playButton = new MenuButton( p1, w1, h1, g, pl, EventHandler * e);
	MenuButton* exitButton = new MenuButton( p2, w1, h1, g, pl, EventHandler * e);

	
	m_gameObjects.push_back(playButton);
	m_gameObjects.push_back(exitButton);
}
