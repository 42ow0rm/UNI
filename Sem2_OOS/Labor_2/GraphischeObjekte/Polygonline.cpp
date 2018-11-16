//Polygonline.cpp
#include <iostream>
#include <vector>
#include "Polygonline.hpp"

using namespace std;

Polygonline::Polygonline(){
	//Point p;
	//addPoint(p);
}

Polygonline::Polygonline(Point p){
	addPoint(p);
}

Polygonline& Polygonline::addPoint(Point p){
	Points.push_back(p);
	return *this;
}

void Polygonline::appendPolygonline(Polygonline pl){
	
	Point p;	
	for(int i=0; i<pl.getSize(); i++){
		p = pl.getPoint(i);
		addPoint(p);
	}
}

void Polygonline::move(double m_x, double m_y){
	
	Point p;	
	for(int i=0; i<Points.size(); i++){
		p = Points[i];
		p.move(m_x, m_y);
		Points[i] = p;
	}	
}

void Polygonline::toString(){

	Point p;	
	cout << "|";
	for(int i=0; i<Points.size(); i++){
		if(i > 0){
			cout << " - ";	
		}
		p = Points[i];
		p.toString(false);
	}
	cout << "|" << endl;
}

Point Polygonline::getPoint(int tmp){
	return Points[tmp];
}

int Polygonline::getSize(){
	return Points.size();
}
