#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Coche
{
private:
	int codigo;
	int precio;
	string nombre;

public:
	Coche() : codigo(0), precio(0), nombre("") {};
	Coche(int codigo, int precio, string nombre);

	int getCodigo()const;
	int getPrecio()const;
	string getName()const;

	// Metodo para cargar los elementos del coche (ifstream)
	bool cargarElemCoches(string FICHERO_COCHES);
	void darValores(int code, string name, int price);
};

