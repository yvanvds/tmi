#include "stdafx.h"
#include "Square.h"
#include "Coordinate.h"
#include "Event.h"

Event::Event()
{
}

Event::Event(bool isLeftEdge, Square sq, double xcoor){
	type = isLeftEdge;
	square = sq;
	x = xcoor;
}

bool Event::isLeftEdge(){
	return type;
}

Square Event::getSquare(){
	return square;
}

double Event::getX(){
	return x;
}
