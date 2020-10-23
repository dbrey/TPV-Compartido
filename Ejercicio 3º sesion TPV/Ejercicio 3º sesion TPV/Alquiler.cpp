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
	bool read = true;
	/*ifstream input;
	input.open(RENT);*/

	// Comprobamos si el fichero se ha encontrado y esta abierto
	if (!RENT.is_open())
	{
		cout << "Fichero no encontrado\n";
		//read = false;
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
			//read = false;
		}

		RENT.ignore();
		RENT >> diasA;

	}

	return read;
}

void Alquiler::darValores(Coche* c, int code, Date f, int dA) {
	coche = c;
	codigo = code;
	fecha = f;
	diasA = dA;
}

/*void Alquiler::meterAlquiler(int PCoche, int code, Date date, int daysA, ListaCoches NCoches)
{
	coche = NCoches.coches[PCoche];

	codigo = code;
	fecha = date;
	diasA = daysA;
}*/



