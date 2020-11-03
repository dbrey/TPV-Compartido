// Grupo 2
// David Brey Plaza
// Pablo Gonzalez Alvarez
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date() : day(0), month(0), year(0) {};
	Date(int d, int m, int y);
	Date(const Date& date);
	void operator++();
	void operator+=(int n);
	bool operator<(const Date& date) const;
	int diff(const Date& date) const;
	void print() const;
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& in, const Date& d);

	bool cargarFecha(ifstream& entrada);
	void pedirFecha(int anyo, int mes, int dia);

private:
	int daysInMonth(int m) const;
	int calculateValue() const;
	bool correctDate() const;
};

#endif /* DATE_H_ */

