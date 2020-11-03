
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>


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

		input >> tamCellX;
		input.ignore();
		string aux;
		getline(input, aux);
		tamCellY = stoi(aux, nullptr, 10); //Convierte string a int
		
		int aux2;
		for (int i = 0; i < tamCellX; i++)
		{
			for (int j = 0; j < tamCellY; j++)
			{
				input >> aux2;
				if (aux2 == 0)
				{
					mapa.WriteCell(j, i, MapCell.)
				}
				else if (aux2 == 1)
				{
					mapa.WriteCell( j,  i, MapCell estado)
				}
				else if (aux2 = 2)
				{
					mapa.WriteCell( j,  i, MapCell estado)
				}
				else
				{
					mapa.WriteCell( j,  i, MapCell estado)
				}
			}
		}
	}
	// Cerramos el input
	input.close();
	return read;
}