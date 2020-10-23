#include "Coche.h"


// Quitar todos los constructores (Alquiler...)

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
bool Coche::cargarElemCoches(ifstream& input)
{	
		input >> codigo;
		input >> precio;
		input.ignore(); // Esto es para ignorar el siguiente espacio (ya que si no se mete en el siguiente string)
		getline(input, nombre);
		input.close();
		return true;
}

void  Coche::darValores(int code, string name, int price)
{
	codigo = code;
	nombre = name;
	precio = price;
}