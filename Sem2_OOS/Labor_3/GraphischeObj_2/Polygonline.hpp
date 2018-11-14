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
		Polygonline(Point p);
		Polygonline(int* points);
		Polygonline(string str);
	
		Polygonline& addPoint(Point p);
		void appendPolygonline(Polygonline pl);
		void move(double m_x, double m_y);
		string toString();
		
		Point getPoint(int tmp);
		int getSize();
		Point getPoint(unsigned int i);
	private:
		// Protected Declarations
		vector<Point> Points;
};

ostream & operator << (ostream & out, Polygonline & pl);
istream & operator >> (istream & in, Polygonline & pl);
