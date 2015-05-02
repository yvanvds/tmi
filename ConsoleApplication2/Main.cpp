// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Coordinate.h"
#include "LineParser.h"
#include "Square.h"
#include "Algorithm.h"
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
				array.emplace_back(Square(pos));
				pos.clear();
			} else if (count == 1){
				algorithm = stoi(nextLine);
			}
			else if (count == 2){
				array.reserve(stoi(nextLine));
			}
		}
		
		getIntersections(algorithm, array);
		getIntersections(2, array);
		input.close();
	}



	cin.get();
	cin.get();
	return 0;
}

