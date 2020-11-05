#pragma once

#include <iostream>

class Point2D {
private:
	int x;
	int y;

public:
	Point2D(int newx, int newy) {
		x = newx;
		y = newy;
	}

	int getX() { return x; }
	int getY() { return y; }
	void Suma(int i, int j) { x += i; y += j; }
	void Mul(double i) { x *= i; y *= i;}

	bool iguales(Point2D aux) { return (x == aux.getX() && y == aux.getY()); }
};

class Vector2D
{
private:
	Point2D punto;
public:
	Vector2D() : punto(0, 0){};
	Vector2D(int X, int Y) : punto(X, Y) {}
	
	int GetX() { return punto.getX(); }
	int GetY() { return punto.getY(); }
	

	Vector2D operator+(Point2D p) const;
	Vector2D operator*(double i) const;

	// Producto de un vector por un escalar

	bool operator==(const Vector2D& v);
};
