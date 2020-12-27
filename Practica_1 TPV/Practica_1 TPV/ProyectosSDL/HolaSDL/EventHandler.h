#pragma once

class EventHandler
{
public:
	virtual bool handleEvent(SDL_Event& event) = 0;
};

