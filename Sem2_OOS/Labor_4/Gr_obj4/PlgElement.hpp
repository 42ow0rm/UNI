#include "Point.hpp"
#pragma once

struct PlgElement {
	Point point;
	PlgElement* next;

	PlgElement(Point point);
	~PlgElement();
};
