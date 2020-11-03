
#include "Game.h"
#include <iostream>
#include <fstream>



bool Game::LeeArchivo(string archivo)
{
	bool read = true;
    ifstream input;
    input.open(archivo);

	if (!input.is_open())
	{
		cout << "Fichero no encontrado\n";
		read = false;
	}
	else
	{


	}
	// Cerramos el input
	input.close();
	return read;
}