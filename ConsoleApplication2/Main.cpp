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
	std::vector<Square> array;

	ifstream input("inputint.txt");
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
				array.emplace_back(Square(pos));
				pos.clear();
			} else if (count == 1){
				algorithm = stoi(nextLine);
			}
			else if (count == 2){
				array.reserve(stoi(nextLine));
			}
		}

		for (int i = 0; i < array.size(); i++){
			array[i].setId(i);
			//cout << "\nRectangle " << i << " " << array[i].getLB().getX() << " " << array[i].getLB().getY() << " " << array[i].getRA().getX() << " " << array[i].getRA().getY();
		}
		
		//getIntersections(algorithm, array);
		getIntersections(2, array);
		input.close();
	}
	


	/* Test interval tree*/
	/*
	vector<double> pos;
	vector<Square> array;
	pos.emplace_back(4);
	pos.emplace_back(1);
	pos.emplace_back(6);
	pos.emplace_back(3);
	array.emplace_back(Square(pos));
	pos.clear();

	pos.emplace_back(4);
	pos.emplace_back(4);
	pos.emplace_back(6);
	pos.emplace_back(6);
	array.emplace_back(Square(pos));
	pos.clear();

	vector<Interval<Square>> intervals;
	IntervalTree<Square> tree;
	intervals.push_back(Interval<Square>(array[0].getLB().getY(), array[0].getRA().getY(), array[0]));
	intervals.push_back(Interval<Square>(array[1].getLB().getY(), array[1].getRA().getY(), array[1]));
	tree = IntervalTree<Square>(intervals);

	vector<Interval<Square> > results;
	tree.findOverlapping(0, 2, results);
	cout << "found " << results.size() << " overlapping intervals" << endl;
	for (int i = 0; i < results.size(); i++){
		cout << results[i].start << " " << results[i].stop << endl;
	}
	
	*/

	cin.get();
	cin.get();
	return 0;
}

