#include "ListaCoches.h"
#include "Coche.h"

ListaCoches::ListaCoches(int n, int c, Coche* co) {
	numElem = n;
	capacidad = c;
	coches = co;
}

int ListaCoches::getnumElem() const
{
	return numElem;
}

int ListaCoches::getCapacidad() const
{
	return capacidad;
}

Coche* ListaCoches::getCoche() const
{
	return coches;
}

bool ListaCoches::cargarCoches(string FICHERO_COCHES)
{
	bool read = true;
	ifstream input;
	input.open(FICHERO_COCHES);

	// Comprobamos si el fichero se ha encontrado y esta abierto
	if (!input.is_open())
	{
		cout << "Fichero no encontrado\n";
		read = false;
	}
	else
	{
		// Cogemos el numero de coches y declaramos el array
		input >> numElem;

		capacidad = numElem + 10;

		coches = new Coche[capacidad];

		// Leemos cada modelo y asignamos los datos
		int i = 0;
		while (i<numElem && read)
		{
			if (!coches[i].cargarElemCoches(input))
			{
				read = false;
			}
			i++;
		}
	}
	// Cerramos el input
	input.close();
	return read;
}

Coche* ListaCoches::buscarCoche(const int& code) // Pasar por referencia (const& int code)
{
	Coche* aux;
	int cont = 0;
	bool found = false;

	// Buscamos el coche segun su codigo
	while (cont < numElem && code != coches[cont].getCodigo())
	{
		cont++;
	}

	// Si ha llegado hasta el final y no lo ha encontrado, lo declaramos como nulo
	if (cont >= numElem)
	{
		aux = nullptr;
	}
	else // Si lo encuentra, asignamos el puntero de dicho coche
	{
		aux = coches + cont;
	}

	return aux;
}

void ListaCoches::meterCoche(const int& code, const string& name, const int& precio)
{
	if (numElem == capacidad)
	{
		cout << "Lista llena \n";
	}
	else
	{
		coches[numElem].darValores(code, name, precio);
		numElem++;
	}
}

void ListaCoches::del()
{	
	delete[] coches;
}