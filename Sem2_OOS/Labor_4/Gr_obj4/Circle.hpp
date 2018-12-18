#pragma once
#include <string>
#include "Point.hpp"
#include "OneDimObject.hpp"

class Circle : public OneDimObject
{
    public:
        Circle(Point centre = Point(), double radius = 0);
		  Circle(const std::string s);
		  Point getCentre() const;
        double getRadius() const;
        void setCentre(Point centre);
        void setRadius(double radius);
        void move(double dx, double dy);
        void print(bool endl=true) const;
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream&, const Circle&);
    private:
        Point centre;
        double radius;
};
