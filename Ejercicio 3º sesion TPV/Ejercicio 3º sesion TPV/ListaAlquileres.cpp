#include "ListaAlquileres.h"
#include <algorithm>

ListaAlquileres::ListaAlquileres(int n, int c, Alquiler* a) {
	numElem = n;
	capacidad = c;
	alquileres = a;
}

int ListaAlquileres::getnumElem() const
{
	return numElem;
}

int ListaAlquileres::getCapacidad() const
{
	return capacidad;
}

Alquiler* ListaAlquileres::getAlquiler() const
{
	return alquileres;
}

void ListaAlquileres::ordenarAlquileres()const
{
	sort(alquileres, alquileres + numElem);
}

bool ListaAlquileres::leeAlquileres(string RENT, ListaCoches NCoches)
{
	bool read = true;
	ifstream input;
	input.open(RENT);

	// Comprobamos si el fichero se ha encontrado y esta abierto
	if (!input.is_open())
	{
		cout << "Fichero no encontrado\n";
		return false;
	}
	else
	{
		// Leemos y declaramos el array de alquileres
		input >> numElem;

		capacidad = numElem + 10;

		alquileres = new Alquiler[capacidad];

		// Leemos cada modelo y asignamos los datos
		int i = 0;
		while (i < numElem && read)
		{
			if (!alquileres[i].cargarElemAlquiler(input, NCoches))
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

void ListaAlquileres::ordenarAlquileres()
{
	sort(alquileres, alquileres + numElem);
}

void ListaAlquileres::mostrarAlquileres()
{
	for (int i = 0; i < numElem; i++)
	{
		cout << alquileres[i].getFecha();

		if (alquileres[i].getCoche() == nullptr)
		{
			cout << " ERROR: Modelo inexistente \n";
		}
		else
		{
			cout << " "<< alquileres[i].getCoche()->getName()<< " " << alquileres[i].getDiasA() << " dia(s) por " << alquileres[i].getCoche()->getPrecio()* alquileres[i].getDiasA() << " euros \n";
		}
	}
}

void ListaAlquileres::meterAlquiler(int PCoche, int codigo, Date fecha, int diasA, ListaCoches NCoches) {


	if (numElem == capacidad) {
		cout << "Lista llena \n";
	}
	else {
		alquileres[numElem].darValores(NCoches.buscarCoche(codigo), codigo, fecha, diasA);
		numElem++;
	}


}