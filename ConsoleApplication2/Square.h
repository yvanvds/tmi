#pragma once
#include <vector>
#include"Coordinate.h"
#include"IntervalTree.h"

using namespace std;


class Square
{

private:
	Coordinate LB;
	Coordinate RA;
	int id;

public:
	Square();
	Square(const vector<double> & coordinates);

	Coordinate getLB();
	Coordinate getRA();

	double getWidth();
	double getHeight();

	int getId();
	void setId(int id);
	SQINTERVAL getInterval();

	bool intersects(Square square, vector<Coordinate> & points);
	Square getBoundingRectangle(Square square, vector<double> pos);
	void Square::getIntersection(Square square, vector<Coordinate> & pos);
};

