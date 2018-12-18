#pragma once
#include <string>
#include "DrawingObject.hpp"

class Point : public DrawingObject {
    public:
        // using DrawingObject::operator=;

		  Point(double x = 0, double y = 0);
        Point(const std::string s);
        Point(const Point &);
		  ~Point();
		  double getX() const;
        double getY() const;
        void setX(double x);
        void setY(double y);
        void move(double dx, double dy);
        void print(bool endl=true) const;
        std::string toString() const;
        Point operator+(const Point& p) const;
        Point operator+(const double d) const;
		  Point operator-(const Point& p) const;
		  Point operator-() const;
		  Point& operator++();
		  Point operator++(int);
		  friend std::ostream& operator<<(std::ostream&, const Point&);
		  friend Point operator+(const double d, const Point &p);
		  
    private:
        double x,y;

};

std::istringstream& operator>>(std::istringstream & is, Point& p);
