#pragma once
#include "PacManError.h"
#include "checkML.h"


class SDLError : public PacManError
{

public:
	SDLError(string& m) : PacManError(m) {};
	void SDLGetError(string& m);
	void IMG_GetError() {};
	void TTF_GetError();
};

