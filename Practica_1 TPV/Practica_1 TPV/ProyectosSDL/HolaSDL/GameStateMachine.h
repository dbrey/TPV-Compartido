#pragma once
#include <stack>
#include "GameState.h"
#include "checkML.h"
using namespace std;

class GameStateMachine
{
private:

	stack<GameState*> states;

public:

	GameState* currentState() {	return states.top(); };
	void pushState(GameState* state) { states.push(state); }
	void changeState(GameState* state) { popState(); pushState(state); };
	void popState();

	~GameStateMachine();
};

