#pragma once
#include "PacManError.h"

class SDLError : public PacManError
{
private:

public:
	void SDLGetError();
	void IMG_GetError();
	void TTF_GetError();
};

