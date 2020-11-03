// Grupo 2
// David Brey Plaza
// Pablo Gonzalez Alvarez
#pragma once
#include "Alquiler.h"

class ListaAlquileres
{
private:
	int numElem; // Coches en el vector
	int capacidad; // Maximo de alquileres
	Alquiler* alquileres;

public:
	ListaAlquileres() : numElem(0), capacidad(0), alquileres() {};
	ListaAlquileres(int n, int c, Alquiler* a);

	int getnumElem()const;
	int getCapacidad()const;
	Alquiler* getAlquiler()const;

	void ordenarAlquileres()const;

	bool leeAlquileres(string RENT, ListaCoches NCoches);

	void ordenarAlquileres();

	void mostrarAlquileres();

	void meterAlquiler(const int& PCoche,const int& codigo,const Date& fecha,const int& diasA, ListaCoches NCoches);

	void del();
};

