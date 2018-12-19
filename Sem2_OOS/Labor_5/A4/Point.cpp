#include "Point.hpp"
#include <iostream>
#include <sstream>

Point::Point(double x/*=0*/, double y/*=0*/)
{
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse Point, Objekt: " << getId()
			<< std::endl;
	this->x = x;
	this->y = y;
}

Point::Point(const std::string s) {
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse Point, Objekt: " << getId()
			<< std::endl;
	float x = 0.0, y = 0.0;

	sscanf(s.substr(s.find("(")).c_str(), "(%f, %f)", &x, &y);

	this->x = x, this->y = y;
}

Point::Point(const Point & p) {
	x = p.x;
	y = p.y;
	if (debugConstructor)
		std::cout << "Kopierkonstruktor der Klasse Point, Objekt: " << getId()
			<< std::endl;
}
Point::~Point() {
	if (debugConstructor)
		std::cout << "Destruktor der Klasse Point, Objekt: " << getId()
			<< std::endl;
}
	
void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

void Point::move(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::print(bool endl /*=true*/) const
{
    std::cout << "(" << this->x << ", ";
    std::cout << this->y <<")"; 
    if(endl)
    {
        std::cout << std::endl;
    }
}

std::string Point::toString() const
{
    using namespace std;
    ostringstream out;
    out << "(" <<this->x << ", " << this->y << ")";
    return out.str();
}

std::istringstream& operator>>(std::istringstream & is, Point &p) {
	Point tmp = Point(is.str());
	p.setX(tmp.getX());
	p.setY(tmp.getY());
	return is;
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << p.toString();
    return out;
}

Point Point::operator+(const Point& p) const {
	return Point(x + p.x, y + p.y);
}

Point Point::operator+(const double d) const {
	return Point(x + d, y + d);
}

Point Point::operator-(const Point& p) const {
	return Point(x - p.y, y - p.y);
}

Point Point::operator-() const {
	return Point(-x, -y);
}

Point Point::operator++(int) {
	Point p = *this;
	move(1, 1);
	return p;
}

Point& Point::operator++() {
	move(1, 1);
	return *this;
}
Point operator+(const double d, const Point &p) {
	return Point(p.x + d, p.y + d); 
}

