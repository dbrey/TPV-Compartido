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

	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& d) const;

	bool operator==(const Vector2D& v);
};
