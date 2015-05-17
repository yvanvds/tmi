#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Square.h"

using namespace std;

void getIntersections(int algorithm, vector<Square> squares);
void algorithm1(vector<Square> squares);
void algorithm2(vector<Square> squares);
void algorithm3(vector<Square> squares);
void generateRectangles(int algorithm, int number);

