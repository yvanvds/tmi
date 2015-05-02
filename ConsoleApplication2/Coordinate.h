#pragma once
class Coordinate
{
public:
	Coordinate();
	Coordinate(double x, double y);

private:
	double x;
	double y;
public:
	double getX();
	double getY();
	Coordinate & setX(double x);
	Coordinate & setY(double y);
};

