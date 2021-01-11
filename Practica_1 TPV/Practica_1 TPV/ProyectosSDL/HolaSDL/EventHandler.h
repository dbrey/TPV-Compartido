#pragma once

class EventHandler
{
public:
	EventHandler() {};
	virtual bool handleEvent(SDL_Event event) = 0;
};

