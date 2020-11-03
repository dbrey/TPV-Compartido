#include "Coche.h"

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

bool Coche::cargarElemCoches(ifstream& input)
{	
		input >> codigo;
		input >> precio;
		input.ignore(); // Esto es para ignorar el siguiente espacio (ya que si no se mete en el siguiente string)
		getline(input, nombre);
		return true;
}

void  Coche::darValores(const int& code,const string& name, const int& price)
{
	codigo = code;
	nombre = name;
	precio = price;
}