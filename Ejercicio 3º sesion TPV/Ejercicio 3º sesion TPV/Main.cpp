// Grupo 2
// David Brey Plaza
// Pablo Gonzalez Alvarez

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include "ListaCoches.h"
#include "ListaAlquileres.h"

using namespace std;

int main()
{
	ListaCoches NCoches = {};
	ListaAlquileres NAlquileres = {};

	if (NCoches.cargarCoches("coches.txt") && NAlquileres.leeAlquileres("rent.txt", NCoches))
	{
		NAlquileres.ordenarAlquileres();
		NAlquileres.mostrarAlquileres();
	}
	
	int opcion = 0;
	int exit = false;
	/*while (!exit)
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
			NAlquileres.mostrarAlquileres();
		}
		else if (opcion = 2)
		{
			int code;
			cout << "Codigo del coche: \n";
			cin >> code;

			string nombre;
			cout << "Nombre del coche: \n";
			cin >> nombre;

			int precio;
			cout << "Precio al dia: \n";
			cin >> precio; 

			NCoches.meterCoche(code, nombre , precio);
		}
		else if (opcion == 3)
		{
			int PCoche;
			cout << "Numero del coche en la lista: \n";
			cin >> PCoche;
			PCoche += NCoches.getnumElem();

			int codigo;
			cout << "Codigo del alquiler: \n";
			cin >> codigo;
			
			Date fecha;
			int anyo, mes, dia;
			cout << "Año: \n";
			cin >> anyo;

			cout << "Mes: \n";
			cin >> mes;

			cout << "Dia: \n";
			cin >> dia;

			fecha.pedirFecha(anyo, mes, dia);

			int diasA;
			cout << "Dias que lleva alquilado el coche: \n";
			cin >> diasA;

			NAlquileres.meterAlquiler(PCoche, codigo, fecha, diasA, NCoches)


		}
		else
		{
			exit = true;
		}
	}
	*/

}