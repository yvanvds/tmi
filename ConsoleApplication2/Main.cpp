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
	//for (int j = 10; j <= 100000000; j *= 10){
		generateRectangles(2, 90);
		string nextLine;
		int count = 0;
		int algorithm = 0;

		vector<double> coordinates; // can hold th coordinates of a square
		vector<Square> rectangles; // the list of rectangles to be analyzed

		ifstream input("invoerrechthoeken.txt");
		if (input.is_open())
		{
			while (getline(input, nextLine))
			{
				count++;
				if (count >= 3)
				{
					parseLine(nextLine, coordinates);
					rectangles.emplace_back(Square(coordinates));
					coordinates.clear();
				}
				else if (count == 1){
					algorithm = stoi(nextLine);
				}
				else if (count == 2){
					rectangles.reserve(stoi(nextLine));
				}
			}

			// give the rectangles an ID so they can be identified
			for (int i = 0; i < rectangles.size(); i++){
				rectangles[i].setId(i);
			}

			// compute intersections
			getIntersections(algorithm, rectangles);
			input.close();
		}
	//}
	cin.get();
	cin.get();
	return 0;
}

