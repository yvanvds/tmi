#pragma once
#include <vector>
#include"Coordinate.h"

using namespace std;


class Square
{

private:
	Coordinate LB;
	Coordinate RA;


public:
	Square();
	Square(const vector<double> & coordinates);

	Coordinate getLB();
	Coordinate getRA();

	double getWidth();
	double getHeight();

	bool intersects(Square square, vector<Coordinate> & points);
	Square getBoundingRectangle(Square square, vector<double> pos);
	void getIntersectionPoints(Square Square, vector<Coordinate> & points);
};

