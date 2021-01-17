#pragma once
#include "PacManError.h"
#include <iostream>
class FileNotFoundError : public PacManError
{
public:
	FileNotFoundError(string& m) : PacManError("No se ha encontrado el fichero " + m){ };

};

