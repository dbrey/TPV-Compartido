#pragma once
#include "PacManError.h"

class FileFormatError : public PacManError
{
public:
	//FileFormatError(string& m) : PacManError(m) {};

	// Escribir si recibe numero negativo o una letra
	void FormatError();
};

