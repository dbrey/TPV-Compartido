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

bool Alquiler::cargarElemAlquiler(string RENT, ListaCoches NCoches)
{
	bool read = true;
	ifstream input;
	input.open(RENT);

	// Comprobamos si el fichero se ha encontrado y esta abierto
	if (!input.is_open())
	{
		cout << "Fichero no encontrado\n";
		read = false;
	}
	else
	{
		// Leemos el codigo del coche y lo buscamos en nuestra lista de coches
		input >> codigo;
		coche = NCoches.buscarCoche(codigo);

		// Meter "Excepciones" con cout
		if (!fecha.cargarFecha(RENT))
		{
			read = false;
		}

		input.ignore();
		input >> diasA;
		input.close();

	}

	return read;
}

/*void Alquiler::meterAlquiler(int PCoche, int code, Date date, int daysA, ListaCoches NCoches)
{
	coche = NCoches.coches[PCoche];

	codigo = code;
	fecha = date;
	diasA = daysA;
}*/



