#include "Point.hpp"

class Circle{
	
public:
	
	Circle(Point c, double r);
	Circle(Point c);
	Circle();
	
	void setCentre(Point tmp_centre);
	Point getCentre();
	void setRadius(double r);
	double getRadius();
	
	void move(double m_x, double m_y);
	void toString(bool = true);
	
private:
		
	Point centre;
	double radius;
	
};
