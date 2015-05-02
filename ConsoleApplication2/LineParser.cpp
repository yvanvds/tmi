#include "stdafx.h"
#include "LineParser.h"
#include <string>


bool parseLine(const string & line, vector<double> & result)
{
	string sub;
	for (unsigned int i = 0; i < line.size(); i++) {
		if (line[i] != ' ') {
			sub += line[i];
		}
		else {
			result.push_back(stod(sub));
			sub.clear();
		}
	}
	
	result.push_back(stod(sub));

	return true;
}