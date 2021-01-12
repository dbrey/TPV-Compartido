#pragma once
#include "PacManError.h"
#include "checkML.h"

class FileFormatError : public PacManError
{
public:
	FileFormatError(const string& m) : PacManError("Se ha introducido un nombre no correspondiente " + m) {};
	FileFormatError(const string& m,const int& n) : PacManError("Se ha introducido un " + n + m) {};
	FileFormatError(const string& m, const string& x) : PacManError("Se ha introducido un string" + x) {};
};

