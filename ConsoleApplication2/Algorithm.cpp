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
	
	vector<Coordinate> results;
	ofstream output;
	output.open("uitvoerrechthoeken.txt");

	auto start = std::chrono::steady_clock::now();

	cout << endl;
	for (int i = 0; i < squares.size(); i++){
		for (int j = i; j < squares.size(); j++){
			if (i != j){
				
				squares[i].intersects(squares[j], results);
				
				for (int w = 0; w < results.size(); w++){
					output << results[w].getX() << " " << results[w].getY() << "\n";
					//cout << results[w].getX() << " " << results[w].getY() << endl;
				}
				cout << endl;
				results.clear();
			}
		}
	}

	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	output << elapsed.count()/1000.0 << "\n";
	output.close();
	
}

void algorithm2(vector<Square> squares){
	
	priority_queue<Event, vector<Event>, CompareEvent> events;
	vector<SQINTERVAL> intervals;
	IntervalTree<Square, float> activeTree;
	vector<SQINTERVAL> results;
	ofstream output;
	output.open("uitvoerrechthoeken.txt");

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
			//cout << "Add rectangle " << current.getSquare().getId() << " to active tree \n";
			// left side of rectangle: add to 
			if (intervals.size() > 0){
				//cout << "we test intersection for the interval [" << current.getSquare().getLB().getY() << "," << current.getSquare().getRA().getY() << "] \n";
				activeTree.findOverlapping(current.getSquare().getLB().getY(), current.getSquare().getRA().getY(), results);
				vector<Coordinate> pos;
				for (int i = 0; i < results.size(); i++){
					//cout << "the overlapping interval is [" << results[i].start << "," << results[i].stop << "] \n";
					//cout << "the overlapping rectangle is " << results[i].value.getId() << endl;
					//cout << "found " << results.size() << " overlapping intervals" << endl;
					//cout << "\nRectangle " << current.getSquare().getId() << " intersects Rectangle " << results[i].value.getId() << "\n";
					results[i].value.getIntersection(current.getSquare(), pos);
					for (int w = 0; w < pos.size(); w++){
						//cout << pos[w].getX() << " " << pos[w].getY() << endl;
						output << pos[w].getX() << " " << pos[w].getY() << "\n";
					}
					//cout << endl;
					pos.clear();
				}
			}
			intervals.push_back(SQINTERVAL(current.getSquare().getInterval()));
			activeTree = IntervalTree<Square, float>(intervals);
			results.clear();
		}
		else {
			//cout << "Remove rectangle " << current.getSquare().getId() << " from active tree \n";
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

	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	output << elapsed.count() / 1000.0 << "\n";
	output.close();
}

void algorithm3(vector<Square> squares){
	//TODO
}