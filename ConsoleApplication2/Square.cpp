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

void Square::setId(int number){
	id = number;
}

int Square::getId(){
	return id;
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

Square Square::getBoundingRectangle(Square other, vector<double> pos){

	pos.push_back(min(LB.getX(), other.getLB().getX()));
	pos.push_back(min(LB.getY(), other.getLB().getY()));
	pos.push_back(max(RA.getX(), other.getRA().getX()));
	pos.push_back(max(RA.getY(), other.getRA().getY()));

	return Square(pos);
}

void Square::getIntersection(Square other, vector<Coordinate> & pos){
	vector<double> boundingRectanglePoints;
	Square boundingRectangle = getBoundingRectangle(other, boundingRectanglePoints);

	pos.push_back(Coordinate(max(LB.getX(), other.getLB().getX()), max(LB.getY(), other.getLB().getY())));
	pos.push_back(Coordinate(min(RA.getX(), other.getRA().getX()), min(RA.getY(), other.getRA().getY())));
	//cout << "height bounding rectangle: " << abs(pos[1].getY() - pos[0].getY()) << endl;
	//cout << "height first rectangle: " << getHeight() << endl;
	if (abs(pos[1].getY() - pos[0].getY()) >= getHeight()){
		pos.push_back(Coordinate(pos[0].getX(), pos[0].getY() + getHeight()));
		pos.push_back(Coordinate(pos[1].getX(), pos[1].getY() - getHeight()));

	}
	else if (abs(pos[1].getY() - pos[0].getY()) >= other.getHeight()){
		pos.push_back(Coordinate(pos[0].getX(), pos[0].getY() + other.getHeight()));
		pos.push_back(Coordinate(pos[1].getX(), pos[1].getY() - other.getHeight()));
	}
}
	


