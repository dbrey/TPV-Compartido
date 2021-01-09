#pragma once

class EventHandler
{
public:
	EventHandler() {};
	virtual bool handleEvent() = 0;
};

