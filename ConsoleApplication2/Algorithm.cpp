#include "stdafx.h"
#include "Algorithm.h"
#include "Square.h"
#include "Event.h"
#include "CompareEvent.h"
#include "IntervalTree.h"
#include <queue>
#include <set>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;

void getIntersections(int algorithm, vector<Square> squares){
	if (algorithm == 1){
		algorithm1(squares);
	}
	else if (algorithm == 2){
		algorithm2(squares);
	}
	else{
		algorithm3(squares);
	}
}

void algorithm1(vector<Square> squares){
	
	vector<Coordinate> results; // contains the intersections of all rectangles
	ofstream output;
	output.open("uitvoerrechthoeken.txt");

	// start timer
	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < squares.size(); i++){
		for (int j = i+1; j < squares.size(); j++){
				
				// find intersection between rectangle i and rectangle j
				squares[i].intersects(squares[j], results);
				
				for (int w = 0; w < results.size(); w++){
					output << results[w].getX() << " " << results[w].getY() << "\n";
				}
				results.clear();
		}
	}

	// stop timer
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	output << elapsed.count() << "\n"; 
	output.close();
	cout << "Ready.";
	
}

void algorithm2(vector<Square> squares){
	
	priority_queue<Event, vector<Event>, CompareEvent> events; 
	vector<SQINTERVAL> intervals; // vector containg all vertical intervals and their rectangles
	IntervalTree<Square, float> activeTree; // tree containing the vertical intervals
	vector<SQINTERVAL> results; // contains the intersecting vertical intervals and their rectangles

	ofstream output;
	output.open("uitvoerrechthoeken.txt");

	// start timer
	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < squares.size(); i++){
		Event e1 = Event(true, squares[i], squares[i].getLB().getX());
		Event e2 = Event(false, squares[i], squares[i].getRA().getX());
		events.push( e1 ); //left side event of rectangle
		events.push( e2 ); //right side event of rectangle
	}
	
	while (!events.empty()) {
		Event current = events.top();
		if (current.isLeftEdge()){
			
			if (intervals.size() > 0){
				
				activeTree.findOverlapping(current.getSquare().getLB().getY(), current.getSquare().getRA().getY(), results);
				vector<Coordinate> pos;
				for (int i = 0; i < results.size(); i++){
					
					results[i].value.getIntersection(current.getSquare(), pos);
					for (int w = 0; w < pos.size(); w++){
						output << pos[w].getX() << " " << pos[w].getY() << "\n";
					}
					
					pos.clear();
				}
			}
			intervals.push_back(SQINTERVAL(current.getSquare().getInterval()));
			activeTree = IntervalTree<Square, float>(intervals);
			results.clear();
		}
		else {
			int index = 0;
			for (int i = 0; i < intervals.size(); i++){
				if (current.getSquare().getId() == intervals[i].value.getId()){
					index = i;
				}
			}
			intervals.erase(intervals.begin()+(index));
			activeTree = IntervalTree<Square, float>(intervals);
			results.clear();
		}
		events.pop();
	}

	// stop timer
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	output << elapsed.count() << "\n"; 
	output.close();
}

void algorithm3(vector<Square> squares){
	algorithm2(squares);
}

void generateRectangles(int algorithm, int number){
	float r0, r1, r2, r3;
	ofstream output;
	output.open("invoerrechthoeken.txt");
	output << algorithm << "\n";
	output << number << "\n";
	for (int i = 0; i < number; i++){
		r0 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		r3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		output << r0 << " " << r1 << " " << r2 << " " << r3 << "\n";
	}
	output.close();
}