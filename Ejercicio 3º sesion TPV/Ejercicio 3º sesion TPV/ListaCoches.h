#pragma once
#include "Coche.h"
#include <iostream>
#include <fstream>


class ListaCoches
{
private:
	int numElem; // Coches en el vector
	int capacidad; // Maximo de coches
	Coche* coches;

public:

	ListaCoches() : numElem(0), capacidad(0), coches() {};
	ListaCoches(int numElem, int capacidad, Coche* coches);

	int getnumElem()const;
	int getCapacidad()const;
	Coche* getCoche()const;

	bool cargarCoches(string FICHERO_COCHES);
	Coche* buscarCoche(int code);

	void meterCoche(int code, string name, int precio);
};

