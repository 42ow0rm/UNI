#pragma once
#include <string> 
#include "PlgElement.hpp"
#include "OneDimObject.hpp"

class Polygonline : public OneDimObject {
	PlgElement* start;
	PlgElement* end;

public:
	Polygonline();
	Polygonline(Point point);
	Polygonline(const std::string s);
	~Polygonline();

	Polygonline& addPoint(Point point);
	Polygonline& appendPolygonline(const Polygonline& line);
	Polygonline& move(int dx, int dy);
	Polygonline& print(bool endl = true);
	Polygonline& operator+(const Point &p);
	Polygonline& operator+(const Polygonline &l);
    std::string toString() const;
	void print(bool) const;
    friend std::ostream& operator<<(std::ostream&, const Polygonline&);
};
