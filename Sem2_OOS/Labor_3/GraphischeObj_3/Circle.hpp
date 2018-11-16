#include "Point.hpp"
#include <iostream>
using namespace std;

class Circle{
	
public:
	
	Circle(string str);
	Circle(Point c, double r);
	Circle(Point c);
	Circle();
	
	void setCentre(Point tmp_centre);
	Point getCentre();
	void setRadius(double r);
	double getRadius();
	
	void move(double m_x, double m_y);
	string toString();
	
private:
		
	Point centre;
	double radius;
	
};

ostream & operator << (ostream & out, Circle & c);
istream & operator >> (istream & in, Circle & c);
