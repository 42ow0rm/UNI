#include "Point.hpp"
#include "DrawingObject.hpp"
#pragma once

class Circle : public DrawingObject
{
	private:
		Point centre;			
		double radius;			
		
	public:	
		Circle(Point, double = 0);	//Konstruktor mit Defaultparameter
		~Circle();
		double getRadius() const;
		void move(double, double);
		void print(bool = true) const;
		MyData* clone() const;
		Circle & Circle::operator=(const MyData &);
};