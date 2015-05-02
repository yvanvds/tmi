#include "stdafx.h"
#include "Square.h"
#include <iostream>
#include <algorithm>

using namespace std;

Square::Square()
{
}

Square::Square(const vector<double> & coordinates)
{
	LB.setX(coordinates[0]).setY(coordinates[1]);
	RA.setX(coordinates[2]).setY(coordinates[3]);
}

Coordinate Square::getLB()
{
	return LB;
}

Coordinate Square::getRA()
{
	return RA;
}

double Square::getWidth()
{
	return abs(getRA().getX() - getLB().getX());
}

double Square::getHeight(){
	return abs(getRA().getY() - getLB().getY());
}

bool Square::intersects(Square square, vector<Coordinate> & pos){
	vector<double> boundingRectanglePoints;
	Square boundingRectangle = getBoundingRectangle(square, boundingRectanglePoints);

	if ((boundingRectangle.getWidth() < getWidth() + square.getWidth())
		&& (boundingRectangle.getHeight() < getHeight() + square.getHeight())){
		 
			pos.push_back(Coordinate(max(LB.getX(), square.getLB().getX()), max(LB.getY(), square.getLB().getY())));
			pos.push_back(Coordinate(min(RA.getX(), square.getRA().getX()), min(RA.getY(), square.getRA().getY())));
			//cout << "height bounding rectangle: " << abs(pos[1].getY() - pos[0].getY()) << endl;
			//cout << "height first rectangle: " << getHeight() << endl;
			if (abs(pos[1].getY() - pos[0].getY()) >= getHeight() || abs(pos[1].getY() - pos[0].getY()) >= square.getHeight()){
				pos.push_back(Coordinate(pos[0].getX(), pos[0].getY() + boundingRectangle.getHeight()));
				pos.push_back(Coordinate(pos[1].getX(), pos[1].getY() - boundingRectangle.getHeight()));
		
			}
		return true;
	}
	else {
		return false;
	}
}

Square Square::getBoundingRectangle(Square square, vector<double> pos){
	
	pos.push_back(min(LB.getX(), square.getLB().getX()));
	pos.push_back(min(LB.getY(), square.getLB().getY()));
	pos.push_back(max(RA.getX(), square.getRA().getX()));
	pos.push_back(max(RA.getY(), square.getRA().getY()));
	
	return Square(pos) ;
}


