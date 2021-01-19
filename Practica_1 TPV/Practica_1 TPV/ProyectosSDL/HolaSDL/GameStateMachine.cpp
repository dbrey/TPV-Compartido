#include "GameStateMachine.h"


void GameStateMachine::popState()
{
	if (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}

GameStateMachine::~GameStateMachine()
{
	while (!states.empty())
	{
		states.pop();
	}
}