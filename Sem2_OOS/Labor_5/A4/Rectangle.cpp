#include <iostream>
#include "Rectangle.hpp"


Rectangle::Rectangle(const Point p1/* = Point(0, 0)*/, 
		const Point p2/* = Point(1, 1)*/) : p1(p1), p2(p2) {
}

Rectangle::Rectangle(const std::string s) {
	Point *p1 = new Point(s);
	Point *p2 = new Point(s.substr(s.find(")")));
	
	// FIXME: Zuweisungsoperator implementieren...
	this->p1.setX(p1->getX());
	this->p1.setY(p1->getY());
	this->p2.setX(p2->getX());
	this->p2.setY(p2->getY());
}

void Rectangle::print(bool printEndl) const {
	std::cout << "[" << p1 << ", " << p2 << "]" << (printEndl ? "\n" : "");
}
