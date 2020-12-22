#pragma once
#include "PacManError.h"
#include <iostream>
class FileNotFoundError : public PacManError
{
public:
	// No se ha encontrado el archivo (tanto file como ficheros de textura)
	// Metodo que reciba el nombre del fichero
	void NotFound(string& name) { cout << "No se ha encontrado el fichero " + name; }

};

