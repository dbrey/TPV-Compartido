#pragma once
#include <iostream>
#include "Date.h"
#include "ListaCoches.h"
#include <string>
using namespace std;


class Alquiler
{
private:
	Coche* coche;
	int codigo;
	Date fecha;
	int diasA;

public:
	Alquiler() : coche(), codigo(0), fecha(), diasA(0) {};
	Alquiler(Coche* coche, int codigo, Date fecha, int diasA);

	int getCodigo()const;
	int getDiasA()const;
	Coche* getCoche()const;
	Date getFecha() const;
	bool operator<(const Alquiler& a)const
	{
		return (fecha < a.fecha);
	}

	bool cargarElemAlquiler(string RENT, ListaCoches NCoches);

	void meterAlquiler(int PCoche, int code, Date date, int daysA, ListaCoches NCoches);
};