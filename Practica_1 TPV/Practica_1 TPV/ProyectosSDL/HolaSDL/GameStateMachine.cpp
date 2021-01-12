#include "GameStateMachine.h"



void GameStateMachine::changeState(GameState* state)
{
	popState();
	pushState(state);
}

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
		delete states.top();
		states.pop();
	}
}