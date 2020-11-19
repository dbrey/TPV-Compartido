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

// Dependiendo de la direccion tomada, mueve el punto dado y comprueba si ha llegado hasta el final de los pasillos
void Vector2D::movimiento(Point2D& point) {
	int x = punto.getX(), y = punto.getY();
	point.Suma(x, y);

	Point2D izq(0, 15), der(28, 15);
	if (point.iguales(izq))
	{
		point.SetPos(27, 15);
	}
	else if (point.iguales(der))
	{
		point.SetPos(1, 15);
	}
}

bool Vector2D::operator==(const Vector2D& v)
{
	return punto.iguales(v.punto) ;
}