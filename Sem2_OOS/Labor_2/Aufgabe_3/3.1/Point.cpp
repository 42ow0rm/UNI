#include <iostream>
#include "Point.hpp"

using namespace std;

Point::Point(){
	setX(0);	
	setY(0);	
}

Point::Point(double tmp_x = 0, double tmp_y = 0){
	setX(tmp_x);	
	setY(tmp_y);	
}

void Point::setX(double tmp_x){
	x = tmp_x;	
}

void Point::setY(double tmp_y){
	y = tmp_y;
}

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

void Point::move(double m_x, double m_y){
	setX(x + m_x);
	setY(y + m_y);
}

void Point::toString(bool end_line){
	cout << "(" << getX() << "," << getY() << ")";
	if (end_line){
		cout << endl;
	}
}
