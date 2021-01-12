#include "MainMenuState.h"
#include "checkML.h"

void MainMenuState::update()
{
	list<MenuButton*>::iterator it = m_gameObjects.begin();

	while (it != m_gameObjects.end())
	{
		if ((*it)->update()) //click en el botton
		{
			s_menuToPlay();
			break;
		}
		it++;
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

bool MainMenuState::onEnter()
{
	if (::Instance()->load("assets/button.png", 2,2) || !::Instance()->load("assets/exit.png", 2, 2))
	{
		return false;
	}
	
	MenuButton* playButton(Point2D p, int w1, int h1, g, pl, EventHandler * e);
	MenuButton* exitButton(Point2D p, int w1, int h1, g, PlayState * pl, EventHandler * e);

	
	m_gameObjects.push_back(playButton);
	m_gameObjects.push_back(exitButton);

	std::cout << "entering MenuState\n";
	return true;

}

void MainMenuState::s_menuToPlay()
{
	
}