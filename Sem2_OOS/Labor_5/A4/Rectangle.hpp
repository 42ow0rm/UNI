#pragma once

#include <string>
#include "OneDimObject.hpp"
#include "Point.hpp"

class Rectangle: public OneDimObject {
	Point p1, p2;
public:
	Rectangle(const Point p1 = Point(0, 0), const Point p2 = Point(1, 1));
	Rectangle(const std::string);
	void print(bool) const;
};
