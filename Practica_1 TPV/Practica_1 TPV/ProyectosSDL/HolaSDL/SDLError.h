#pragma once
#include "PacManError.h"
#include "checkML.h"


class SDLError : public PacManError
{

public:
	SDLError(string const m) : PacManError("SDL Error: " + m) {};
	
};

