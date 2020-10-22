// Grupo 2
// David Brey Plaza
// Pablo Gonzalez Alvarez

#include <iostream>
#include <string>;
#include <algorithm>;
#include <vector>;
#include <iostream>;
#include <fstream>;
#include "Date.cpp"
#include "ListaCoches.cpp"
#include "ListaAlquileres.cpp"

using namespace std;

int main()
{
	ListaCoches NCoches = {};
	ListaAlquileres NAlquileres = {};

	if (NCoches.cargarCoches("coches.txt") && NAlquileres.leeAlquileres("rent", NCoches))
	{
		NAlquileres.ordenarAlquileres();
	}
	
	int opcion = 0;
	int exit = false;
	while (!exit)
	{
		do
		{
			cout << "-------------------------------------------------------------------- \n";
			cout << "Bienvenido a la lista de coches y alquileres, que le gustaria hacer? \n";
			cout << "Pulse 1 para ver los alquileres        Pulse 2 para añadir un coche \n";
			cout << "Pulse 3 para añadir un alquiler                   Pulse 4 para salir \n";
			cout << "-------------------------------------------------------------------- \n";

			cin >> opcion;

		} while (opcion <= 0 || opcion > 4);

		if (opcion == 1)
		{
			if (NCoches.cargarCoches("coches.txt") && NAlquileres.leeAlquileres("rent", NCoches))
			{
				NAlquileres.ordenarAlquileres();
			}
		}
		else if (opcion = 2)
		{

		}
		else if (opcion == 3)
		{

		}
		else
		{
			exit = true;
		}
	}
	

}