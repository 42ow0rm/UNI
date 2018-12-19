#include "Circle.hpp"

Circle::Circle(Point centre, double radius) : centre(centre),radius(radius)
{
}

Circle::~Circle()
{};

double Circle::getRadius() const
{
	return radius;
};

void Circle::move(double dx, double dy)
{
	centre.move(dx, dy);
};

void Circle::print(bool Eingabe) const
{
	cout << "Die Koordinaten des Kreises sind: " << centre.getX() << "/" << centre.getY() << " Radius: " << getRadius();	
	if (Eingabe) cout << endl;
};

MyData* Circle::clone() const
{
	return new Circle(*this);
};

Circle & Circle::operator=(const MyData &a) 
{
	const Circle * ptr = dynamic_cast<Circle*>(const_cast<MyData*>(&a));
	centre = ptr->centre;
	radius = ptr->radius;
	return *this;
};
	
