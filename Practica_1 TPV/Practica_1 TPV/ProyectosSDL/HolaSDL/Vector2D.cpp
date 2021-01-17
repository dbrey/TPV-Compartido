#include "Vector2D.h"

Vector2D Vector2D::operator+(Point2D p) const
{
	Vector2D r;
	r.punto = punto;
	r.punto.Suma(p.getX(), p.getY());
	return r;
}


Vector2D Vector2D::operator*(int i) const
{
	Vector2D r;
	r.punto = punto;
	r.punto.Mul(i);
	return r;
}



bool Vector2D::operator==(const Vector2D& v)
{
	return punto.iguales(v.punto) ;
}