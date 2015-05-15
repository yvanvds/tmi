// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Coordinate.h"
#include "LineParser.h"
#include "Square.h"
#include "Algorithm.h"
#include "IntervalTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	
	string nextLine;
	int count = 0;
	int algorithm = 0;

	vector<double> pos;
	std::vector<Square> rectangles;

	ifstream input("input.txt");
	if (input.is_open())
	{
		cout << "The following file is being read: \n\n";
		while (getline(input, nextLine))
		{
			cout << nextLine << '\n';
			count++;
			if (count >= 3)
			{
				parseLine(nextLine, pos);
				rectangles.emplace_back(Square(pos));
				pos.clear();
			} else if (count == 1){
				algorithm = stoi(nextLine);
			}
			else if (count == 2){
				rectangles.reserve(stoi(nextLine));
			}
		}

		for (int i = 0; i < rectangles.size(); i++){
			rectangles[i].setId(i);
			//cout << "\nRectangle " << i << " " << array[i].getLB().getX() << " " << array[i].getLB().getY() << " " << array[i].getRA().getX() << " " << array[i].getRA().getY();
		}
		
		//getIntersections(algorithm, array);
		getIntersections(2, rectangles);
		input.close();
	}
	


	/* Test interval tree*/
	/*
	vector<double> pos;

	// array of squares
	vector<Square> array;

	// square 0
	pos.emplace_back(4);
	pos.emplace_back(1);
	pos.emplace_back(6);
	pos.emplace_back(3);
	array.emplace_back(Square(pos));
	pos.clear();

	// square 1
	pos.emplace_back(4);
	pos.emplace_back(4);
	pos.emplace_back(6);
	pos.emplace_back(6);
	array.emplace_back(Square(pos));
	pos.clear();

	// square 2
	pos.emplace_back(4);
	pos.emplace_back(2);
	pos.emplace_back(5);
	pos.emplace_back(3);
	array.emplace_back(Square(pos));
	pos.clear();

	// square 3
	pos.emplace_back(3);
	pos.emplace_back(3);
	pos.emplace_back(7);
	pos.emplace_back(9);
	array.emplace_back(Square(pos));
	pos.clear();


	// intervals contains all intervals and is used to convert to an interval tree
	vector<Interval<Square>> intervals;
	IntervalTree<Square> tree;
	intervals.push_back(Interval<Square>(array[0].getLB().getY(), array[0].getRA().getY(), array[0]));
	intervals.push_back(Interval<Square>(array[1].getLB().getY(), array[1].getRA().getY(), array[1]));
	intervals.push_back(Interval<Square>(array[2].getLB().getY(), array[2].getRA().getY(), array[2]));
	intervals.push_back(Interval<Square>(array[3].getLB().getY(), array[3].getRA().getY(), array[3]));

	// convert the vector of intervals to an interval tree
	tree = IntervalTree<Square>(intervals);

	// results will contain all the overlapping intervals
	vector<Interval<Square> > results;

	// find all overlapping intervals with [0,2]
	tree.findOverlapping(0, 2, results);

	// output
	cout << "found " << results.size() << " overlapping intervals" << endl;
	for (int i = 0; i < results.size(); i++){
		cout << "[ " << results[i].start << ", " << results[i].stop << " ] from square with coordinates " << results[i].value.getLB().getX() << " " << results[i].value.getLB().getY() << " " << results[i].value.getRA().getX() << " " << results[i].value.getRA().getY() << endl;
	}
	*/

	cin.get();
	cin.get();
	return 0;
}

