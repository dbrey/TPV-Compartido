#pragma once

#include <iostream>
using Point2D = Vector2D; //??

class Vector2D
{
private:
	// Crear una clase Point2D con X e Y como privados, 
	int x;
	int y;
public:
	Vector2D() : x(0), y(0){};
	Vector2D(int X, int Y) {x = X; y = Y;}
	
	int GetX()const { return x; }
	int GetY()const { return y; }

	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& d) const;

	bool operator==(const Vector2D& v);
};
