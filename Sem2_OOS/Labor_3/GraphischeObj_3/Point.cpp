#include <iostream>
#include "string.h"
#include "Point.hpp"
#include "MyString.hpp"

using namespace std;

string removeCharFromString(string &str, char charToRemove) {
	string output;
	output.reserve(str.size()); // optional, avoids buffer reallocations in the loop
	for(size_t i = 0; i < str.size(); ++i)
		if(str[i] != charToRemove) output += str[i];
		
	return output;
}

Point::Point(){
	setX(0);	
	setY(0);	
}

Point::Point(string str){
	str = removeCharFromString(str, ' ');
	int end_pos = 1;
	double x, y = 0;
	string pt;
	string delimiter = ",";
	str = removeCharFromString(str, '(');
	while (str.at(end_pos) != ')'){
		end_pos++;
	}
	for(size_t i = 0; i < end_pos; ++i)
		pt += str[i];
		
	pt = removeCharFromString(pt, ')');	
	//cout << pt;
		size_t pos = 0;
	string token;
	while ((pos = pt.find(delimiter)) != string::npos) {
	    token = pt.substr(0, pos);
	    //cout << token;
		x = atof(pt.c_str());
	    pt.erase(0, pos + delimiter.length());
	}
	//cout << clean_line << endl;	
	y = atof(pt.c_str());
	//cout << x << endl << y << endl;	
	setX(x);	
	setY(y);	
}

Point::Point(double tmp_x = 0, double tmp_y = 0){
	setX(tmp_x);	
	setY(tmp_y);	
}

void Point::setX(double tmp_x){
	x = tmp_x;	
}

void Point::setY(double tmp_y){
	y = tmp_y;
}

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

void Point::move(double m_x, double m_y){
	setX(x + m_x);
	setY(y + m_y);
}

string Point::toString(){
	string res;
	res.append("(");
	res.append(to_string(getX())); //str convert double to string
	res.append(", ");
	res.append(to_string(getY()));	
	res.append(")");
	return res;
}

Point Point::operator+ (const Point& p){
	setX(x + p.x);
	setY(y + p.y);
	return *this;
}

Point Point::operator+ (double d){
	setX(x - d);
	setY(y - d);
	return *this;
}


Point Point::operator- (const Point& p){
	setX(x - p.x);
	setY(y - p.y);
	return *this;
}

Point Point::operator- (double d){
	setX(x - d);
	setY(y - d);
	return *this;
}

Point Point::operator- () const{ 
	return Point(-(this->x), -(this->y));	
}

//prefix
Point& Point::operator++ (){
	setX((this->x) + 1);
	setY((this->y) + 1);
	return *this;	
}

//sufix
Point& Point::operator++ (int i){
	setX((this->x) + 1);
	setY((this->y) + 1);
	return *this;
}

Point operator+ (double d, const Point p){
	Point p_tmp(0,0);
	p_tmp.setX(p.x + d);
	p_tmp.setY(p.y + d);
	return p_tmp;
}
//
//Point operator+ (Point p, double d){
//	p.setX(p.getX() + d);
//	p.setY(p.getY() + d);
//	return p;
//}

Point Point::operator=(const Point& p){
	setX(p.x);
	setY(p.y);
	return *this;
} 

ostream& operator<< (ostream & s, const Point& p){
	return s << "(" << p.x << ", " << p.y << ")";
}

istream& operator >> (istream & in, const Point &p){
	//str.read(in);
	return in;
}

