#include "stdafx.h"
#include "Coordinate.h"


Coordinate::Coordinate() : x(0), y(0) {}

Coordinate::Coordinate(double x, double y) : x(x), y(y) {}


double Coordinate::getX()
{
	return this->x;
}

Coordinate & Coordinate::setX(double x)
{
	this->x = x;
	return *this;
}


double Coordinate::getY()
{
	return this->y;
}

Coordinate & Coordinate::setY(double y)
{
	this->y = y;
	return *this;
}
