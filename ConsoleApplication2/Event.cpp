#include "stdafx.h"
#include "Square.h"
#include "Coordinate.h"
#include "Event.h"

Event::Event()
{
}

Event::Event(double xcoor, Square sq){
	x = xcoor;
	square = sq;
}

double Event::getX(){
	return x;
}

Square Event::getSquare(){
	return square;
}

