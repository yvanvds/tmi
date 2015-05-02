#include "stdafx.h"
#include "Algorithm.h"
#include "Square.h"
#include "Event.h"
#include "CompareEvent.h"
#include "IntervalTree.h"
#include <queue>
#include <set>

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
	
	vector<Coordinate> pos;
	cout << endl;
	for (int i = 0; i < squares.size(); i++){
		for (int j = i; j < squares.size(); j++){
			if (i != j){
				
				squares[i].intersects(squares[j], pos);
				//TODO: get intersection points
				
				//cout << "square " << i+1 << " intersects square " << j+1 << endl;
					
				//squares[i].getIntersectionPoints(squares[j], pos);
				for (int w = 0; w < pos.size(); w++){
					cout << pos[w].getX() << " " << pos[w].getY() << endl;
				}
				cout << endl;
				pos.clear();
			}
		}
	}
}

void algorithm2(vector<Square> squares){
	//TODO
	
	priority_queue<Event, vector<Event>, CompareEvent> pq;
	vector<Interval<Square>> intervals;
	IntervalTree<Square> activeTree;

	for (int i = 0; i < squares.size(); i++){
		Event e1 = Event(squares[i].getLB().getX(), squares[i]);
		Event e2 = Event(squares[i].getRA().getX(), squares[i]);
		pq.push( e1 ); //left side event of rectangle
		pq.push( e2 ); //right side event of rectangle
	}

	/* Test priorith queue*/
	
	while (!pq.empty()) {
		Event e = pq.top();
		if (e.getX() == e.getSquare().getLB().getX()){
			// left side of rectangle: add to 
			intervals.push_back(Interval<Square>(e.getSquare().getLB().getY(), e.getSquare().getRA().getY(), e.getSquare()));
			activeTree = IntervalTree<Square>(intervals);
			
		}
		
		if (e.getX() == e.getSquare().getRA().getX()){
			// het element dat ik wil verwijderen staat als argument:
			intervals.erase(Interval<Square>(e.getSquare().getLB().getY(), e.getSquare().getRA().getY(), e.getSquare()));
		}
		//cout << e.getX() << endl;
		//cout << active_set.size() << endl;
		pq.pop();
		
	}
	vector<Interval<Square> > results;
	activeTree.findContained(0.2, 0.6, results);

	//cout << results.size() << endl;
	
}

void algorithm3(vector<Square> squares){
	//TODO
}