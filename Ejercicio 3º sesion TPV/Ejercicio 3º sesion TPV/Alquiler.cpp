#include "Alquiler.h"

Coche* Alquiler::getCoche() const
{
	return coche;
}

int Alquiler::getCodigo() const
{
	return codigo;
}

Date Alquiler::getFecha() const
{
	return fecha;
}

int Alquiler::getDiasA() const
{
	return diasA;
}

bool Alquiler::cargarElemAlquiler(ifstream& RENT, ListaCoches NCoches)
{
	// Comprobamos si el fichero se ha encontrado y esta abierto
	if (!RENT.is_open())
	{
		cout << "Fichero no encontrado\n";
	}
	else
	{
		// Leemos el codigo del coche y lo buscamos en nuestra lista de coches
		RENT >> codigo;
		// Pasar por referencia
		coche = NCoches.buscarCoche(codigo);

		// Meter "Excepciones" con cout
		if (!fecha.cargarFecha(RENT))
		{
			return false;
		}

		RENT.ignore();
		RENT >> diasA;

	}

	return true;
}

void Alquiler::darValores(Coche* c,const int& code,const Date& f, const int& dA) {
	coche = c;
	codigo = code;
	fecha = f;
	diasA = dA;
}




