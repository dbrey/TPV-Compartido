#include "MainMenuState.h"

void MainMenuState::update()
{
	list<GameObject*>::iterator it = m_gameObjects.begin();

	while (it != m_gameObjects.end())
	{
		(*it)->update();
		it++;
	}
	
}

void MainMenuState::render()
{
	list<GameObject*>::iterator it = m_gameObjects.begin();

	while (it != m_gameObjects.end())
	{
		(*it)->render();
		it++;
	}
}