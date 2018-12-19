#include "Circle.hpp"
#include <iostream>
#include <sstream>

Circle::Circle(Point centre/*=Point()*/, double radius /*=0*/)
{
    if (debugConstructor)
		 std::cout << "Konstruktor der Klasse Circle, Objekt: " << getId()
			 << std::endl;
	 this->centre.setX(centre.getX());
	 this->centre.setY(centre.getY());
    this->radius = radius;
}

Circle::Circle(const std::string s) {
    if (debugConstructor)
		 std::cout << "Konstruktor der Klasse Circle, Objekt: " << getId()
			 << std::endl;
	float r = 0.0;
	Point tmp = Point(s);
	centre.setX(tmp.getX());
	centre.setY(tmp.getY());

	sscanf(s.c_str(), "%*[^)]), %f>", &r);
	radius = r;
}

void Circle::setCentre(Point centre)
{
    this->centre.setX(centre.getX());
	 this->centre.setY(centre.getY());
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}

Point Circle::getCentre() const
{
    return this->centre;
}

double Circle::getRadius() const
{
    return this->radius;
}

void Circle::move(double dx, double dy)
{
    this->centre.move(dx, dy);
}

void Circle::print(bool endl/*=true*/) const
{
    std::cout << "<";
    this->centre.print(false);
    std::cout << ", ";
    std::cout << this->radius << ">";
    if(endl)
    {
        std::cout << std::endl;
    }
}

std::string Circle::toString() const
{
    using namespace std;
    ostringstream out;
    out << "<" << this->centre.toString() << ", " << this->radius << ">";
    return out.str();
}

std::ostream& operator<<(std::ostream& out, const Circle& c) 
{
    out << c.toString();
    return out;
}

