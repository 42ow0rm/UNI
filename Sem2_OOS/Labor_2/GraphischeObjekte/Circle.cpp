#include <iostream>
#include "Circle.hpp"

using namespace std;

Circle::Circle(){
	Point p;
	setCentre(p);
	setRadius(0);	
}

Circle::Circle(Point c){
	setCentre(c);
	setRadius(0);	
}

Circle::Circle(Point c, double r){
	setCentre(c);
	setRadius(r);
}

void Circle::setCentre(Point tmp_centre){
	centre = tmp_centre;
}

void Circle::setRadius(double r){
	radius = r;
}

Point Circle::getCentre(){
	return centre;
}

double Circle::getRadius(){
	return radius;
}

void Circle::move(double m_x, double m_y){
	centre.move(m_x, m_y);
}

void Circle::toString(bool end_line){
	cout << "<(" << centre.getX() << "," << centre.getY() << "), " << radius << ">";
	if (end_line){
		cout << endl;
	}
}
