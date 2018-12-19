#include "Point.hpp"

Point::Point(double x, double y) : x(x),y(y)
{};

Point::~Point()
{};

double Point::getX() const
{
	return x;
};

double Point::getY() const
{
	return y;
};
			
	
void Point::move(double dx, double dy)
{
	x = x + (dx);
	y = y + (dy);
};

void Point::print(bool Eingabe) const
{
	cout << "Die Koordinaten des Punktes sind: " << getX() << "/" << getY();
	if (Eingabe) cout << endl;
};

MyData* Point::clone() const
{
	return new Point(x, y);
};

MyData & Point::operator=(const MyData &a)
{
	const Point * ptr =	dynamic_cast<Point*>(const_cast<MyData*>(&a));
	x = ptr->x;
	y = ptr->y;
	return *this;
};