// Grupo 2
// David Brey Plaza
// Pablo Gonzalez Alvarez
#pragma once
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
	bool cargarElemCoches(ifstream& input);
	void darValores(const int& code,const string& name, const int& price);
};

