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
	
	priority_queue<Event, vector<Event>, CompareEvent> pq;
	vector<Interval<Square>> intervals;
	IntervalTree<Square> activeTree;
	vector<Interval<Square>> results;

	for (int i = 0; i < squares.size(); i++){
		Event e1 = Event(true, squares[i], squares[i].getLB().getX());
		Event e2 = Event(false, squares[i], squares[i].getRA().getX());
		pq.push( e1 ); //left side event of rectangle
		pq.push( e2 ); //right side event of rectangle
	}
	
	while (!pq.empty()) {
		Event current = pq.top();
		if (current.isLeftEdge()){
			cout << "Add rectangle " << current.getSquare().getId() << " to active tree \n";
			// left side of rectangle: add to 
			if (intervals.size() > 0){
				//cout << "we test intersection for the interval [" << current.getSquare().getLB().getY() << "," << current.getSquare().getRA().getY() << "] \n";
				activeTree.findOverlapping(current.getSquare().getLB().getY(), current.getSquare().getRA().getY(), results);
				vector<Coordinate> pos;
				for (int i = 0; i < results.size(); i++){
					//cout << "the overlapping interval is [" << results[i].start << "," << results[i].stop << "] \n";
					//cout << "the overlapping rectangle is " << results[i].value.getId() << endl;
					//cout << "found " << results.size() << " overlapping intervals" << endl;
					cout << "\nRectangle " << current.getSquare().getId() << " intersects Rectangle " << results[i].value.getId() << "\n";
					results[i].value.getIntersection(current.getSquare(), pos);
					for (int w = 0; w < pos.size(); w++){
						cout << pos[w].getX() << " " << pos[w].getY() << endl;
					}
					cout << endl;
					pos.clear();
				}
			}
			intervals.push_back(Interval<Square>(current.getSquare().getLB().getY(), current.getSquare().getRA().getY(), current.getSquare()));
			activeTree = IntervalTree<Square>(intervals);
			results.clear();
		}
		else {
			cout << "Remove rectangle " << current.getSquare().getId() << " from active tree \n";
			int index = 0;
			for (int i = 0; i < intervals.size(); i++){
				if (current.getSquare().getId() == intervals[i].value.getId()){
					index = i;
				}
			}
			intervals.erase(intervals.begin()+(index));
			activeTree = IntervalTree<Square>(intervals);
			results.clear();
		}
		pq.pop();
	}
}

void algorithm3(vector<Square> squares){
	//TODO
}