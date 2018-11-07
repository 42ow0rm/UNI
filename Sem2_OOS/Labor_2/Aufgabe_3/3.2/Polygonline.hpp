//Polygonline.hpp
#include "Point.hpp"
#include <vector>

using namespace std;

class Polygonline {
	// Private section
	public:
		Polygonline();
		Polygonline(Point p);
		Polygonline(int* points);
	
		Polygonline& addPoint(Point p);
		void appendPolygonline(Polygonline pl);
		void move(double m_x, double m_y);
		void toString();
		
		Point getPoint(int tmp);
		int getSize();
	private:
		// Protected Declarations
		vector<Point> Points;
};


