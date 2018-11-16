#pragma once
#include <iostream>
using namespace std;


class Point{
	
public:
	
	Point();
	Point(string str);
	Point(double tmp_x, double tmp_y);
	
	void setX(double tmp_x);
	void setY(double tmp_y);
	double getX();
	double getY();

	void move(double m_x, double m_y);
	string toString();
		
	Point operator+ (const Point& p);	
	Point operator+ (double d);	
	Point operator- (const Point& p);	
	Point operator- (double d);	
	Point operator- () const;
	
	Point& operator++ ();
	Point& operator++ (int i);
	
	Point operator= (const Point& p);
	
	friend Point operator+ (double d, Point p);
	//friend Point operator+ (Point p, double d);
	

		
	double x;
	double y;
	
};

ostream & operator << (ostream & out, const Point & p);
istream & operator >> (istream & in, const Point & p);

string removeCharFromString(string &str, char charToRemove);

