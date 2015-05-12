#pragma once
#include "Square.h"

class Event
{
private:
	bool type;
	Square square;
	double x;
public:
	Event();
	Event(bool type, Square square, double x);
	bool isLeftEdge();
	Square getSquare();
	double getX();
};

