//Polygonline.hpp
#include "Point.hpp"
#include <vector>
#include <iostream>
using namespace std;


using namespace std;

class Polygonline {
	// Private section
	public:
		Polygonline();
		Polygonline(const Point p);
		Polygonline(int* points);
		Polygonline(string str);
	
		Polygonline& addPoint(const Point p);
		void appendPolygonline(Polygonline pl);
		void move(double m_x, double m_y);
		string toString();
		
		Point getPoint(int tmp);
		int getSize();
		Point getPoint(unsigned int i);
		
		Polygonline operator+ (const Point& p);	
		Polygonline operator+ (const Polygonline& l);	
	

		vector<Point> Points;
};

ostream & operator << (ostream & out, const  Polygonline & pl);
istream & operator >> (istream & in, const Polygonline & pl);
