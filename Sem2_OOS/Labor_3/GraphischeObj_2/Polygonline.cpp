//Polygonline.cpp
#include <iostream>
#include <vector>
#include "Polygonline.hpp"

using namespace std;

Polygonline::Polygonline(){
	//Point p;
	//addPoint(p);
}

Polygonline::Polygonline(string str){
	
	str = removeCharFromString(str, ' ');
	int end_pos = 1;
	string pl;
	string delimiter = "-";
	//str = removeCharFromString(str, '(');
	//str = removeCharFromString(str, ')');
	while (str.at(end_pos) != '|'){
		end_pos++;
	}	
	for(size_t i = 0; i < end_pos; ++i)
		pl += str[i];
		
	pl = removeCharFromString(pl, '|');	
	//cout << pl;
	
	size_t pos = 0;
	string token;
	while ((pos = pl.find(delimiter)) != string::npos) {
	    token = pl.substr(0, pos);
	    //cout << token;
	    addPoint(Point(token));
	    pl.erase(0, pos + delimiter.length());
	}
	addPoint(Point(pl));
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

string Polygonline::toString(){

	Point p;	
	cout << "|";
	for(int i=0; i<Points.size(); i++){
		if(i > 0){
			cout << " - ";	
		}
		p = Points[i];
		cout << p.toString();
	}
	cout << "|" << endl;
	return "";
}

Point Polygonline::getPoint(int tmp){
	return Points[tmp];
}

int Polygonline::getSize(){
	return Points.size();
}

Point Polygonline::getPoint(unsigned int i){
	return this->Points[i];
}

ostream& operator<< (ostream & s, Polygonline& pl){
	Point p;	
	cout << "|";
	for(int i=0; i<pl.getSize(); i++){
		if(i > 0){
			cout << " - ";	
		}
		p = pl.getPoint(i);
		p.toString();
	}
	cout << "|";
	return s << endl;
}

istream& operator >> (istream & in, Polygonline &pl){
	//str.read(in);
	return in;
}

