#pragma once
#include "Square.h"

class Event
{
private:
	double x;
	Square square;
public:
	Event();
	Event(double x, Square square);
	double getX();
	Square getSquare();
};

