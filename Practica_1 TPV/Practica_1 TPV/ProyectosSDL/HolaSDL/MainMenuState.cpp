#include "MainMenuState.h"

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

void MainMenuState::s_menuToPlay()
{
	
}