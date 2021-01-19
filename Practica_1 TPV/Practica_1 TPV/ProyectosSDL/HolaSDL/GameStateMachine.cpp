#include "GameStateMachine.h"

// avanzamos al siguiente estado
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