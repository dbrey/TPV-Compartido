#include "Coche.h"


Coche::Coche() : codigo(), precio(), nombre() {}

Coche::Coche(int codigo, int precio, string name) : codigo(codigo), precio(precio), nombre(name) {}

int Coche::getCodigo() const
{
	return codigo;
}

int Coche::getPrecio() const
{
	return precio;
}

string Coche::getName() const
{
	return nombre;
}

// Carga UNICAMENTE los elementos del coche
bool Coche::cargarElemCoches(string FICHERO_COCHES)
{
	ifstream input;
	input.open(FICHERO_COCHES);

	// Comprobamos si el fichero se ha encontrado y esta abierto
	if (!input.is_open())
	{
		cout << "Fichero no encontrado\n";
		input.close();
		return false;
	}
	else
	{
		input >> codigo;
		input >> precio;
		input.ignore(); // Esto es para ignorar el siguiente espacio (ya que si no se mete en el siguiente string)
		getline(input, nombre);
		input.close();
		return true;
	}
}

void  Coche::darValores(int code, string name, int price)
{
	codigo = code;
	nombre = name;
	precio = price;
}