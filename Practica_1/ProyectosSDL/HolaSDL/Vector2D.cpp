#include "Vector2D.h"

//Vector2D Vector2D::operator+(const Vector2D& v) const
//{
//	Vector2D r;
//	r.x = this->x + v.x; // El this no es necesario. Se pone para ilustrar su uso
//	r.y = this->y + v.y; // Al ser un puntero se debe usar con ->
//	return r;
//}
//
//
//Vector2D Vector2D::operator*(double d) const
//{
//	Point2D r;
//	r.x = punto.x * d;
//	r.y = punto.y * d;
//	return r;
//}
//
//double Vector2D::operator*(const Vector2D& d) const
//{
//	return d.x * x + d.y * y;
//}
//
//bool Vector2D::operator==(const Vector2D& v)
//{
//	return (x == v.x && y == v.y);
//}