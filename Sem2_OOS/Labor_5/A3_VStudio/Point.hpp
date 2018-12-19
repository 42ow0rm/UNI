#include "DrawingObject.hpp"
#pragma once

class Point : public DrawingObject
{
	private:
		double x;			//X-Koordinate vom Punkt
		double y;			//Y-Koordinate vom Punkt
		
	public:	
		Point(double = 0, double = 0);	//Konstruktor mit Defaultparameter
		~Point();
		double getX() const;
		double getY() const;
		void move(double, double);
		void print(bool = true) const;
		MyData* clone() const;
		MyData& operator=(const MyData &);
};