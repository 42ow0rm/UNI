#pragma once
#include <iostream>
using namespace std;


class Point{
	
public:
	
	Point(string str);
	Point(double tmp_x, double tmp_y);
	Point();
	
	void setX(double tmp_x);
	void setY(double tmp_y);
	double getX();
	double getY();

	void move(double m_x, double m_y);
	string toString();
		
private:
		
	double x;
	double y;
	
};

ostream & operator << (ostream & out, Point & p);
istream & operator >> (istream & in, Point & p);

string removeCharFromString(string &str, char charToRemove);

