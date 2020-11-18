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
void Vector2D::movimiento(Point2D& point) {
	if (punto.getX() == -1)
		point.Suma(-1, 0);
	else if (punto.getX() == 1)
		point.Suma(1, 0);
	else if (punto.getY() == -1)
		point.Suma(0, -1);
	else if (punto.getY() == 1)
		point.Suma(0, 1);

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