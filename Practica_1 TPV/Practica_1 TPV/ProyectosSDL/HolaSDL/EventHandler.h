#pragma once
#include "checkML.h"
#include "SDL.h"

class EventHandler
{
public:
	EventHandler() {};
	virtual bool handleEvent(SDL_Event& event) = 0;
};

