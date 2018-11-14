#include <iostream>
#include "Circle.hpp"

using namespace std;


Circle::Circle(string str){
	str = removeCharFromString(str, ' ');
	int end_pos = 1;
	int counter = 0;
	double x, y, r = 0;
	string cir;
	string delimiter = ",";
	str = removeCharFromString(str, '(');
	str = removeCharFromString(str, ')');
	str = removeCharFromString(str, '<');
	while (str.at(end_pos) != '>'){
		end_pos++;
	}
	for(size_t i = 0; i < end_pos; ++i)
		cir += str[i];
		
	cir = removeCharFromString(cir, '>');	
	//cout << cir;
	
	size_t pos = 0;
	string token;
	while ((pos = cir.find(delimiter)) != string::npos) {
	    token = cir.substr(0, pos);
	    //cout << token;
		if (counter == 0){
			x = atof(cir.c_str());
		} else {
			y = atof(cir.c_str());	
		}
		cir.erase(0, pos + delimiter.length());
		counter++;
	}
	//cout << clean_line << endl;	
	r = atof(cir.c_str());
	//cout << x << endl << y << endl << r << endl;	

	Point p(x, y);
	setCentre(p);
	setRadius(r);
	
	//cout << px << py << r << endl;
	
}

Circle::Circle(){
	Point p;
	setCentre(p);
	setRadius(0);	
}

Circle::Circle(Point c){
	setCentre(c);
	setRadius(0);	
}

Circle::Circle(Point c, double r){
	setCentre(c);
	setRadius(r);
}

void Circle::setCentre(Point tmp_centre){
	centre = tmp_centre;
}

void Circle::setRadius(double r){
	radius = r;
}

Point Circle::getCentre(){
	return centre;
}

double Circle::getRadius(){
	return radius;
}

void Circle::move(double m_x, double m_y){
	centre.move(m_x, m_y);
}

string Circle::toString(){
	string res;
	res.append("<(");
	res.append(to_string(centre.getX())); //str convert double to string
	res.append(", ");
	res.append(to_string(centre.getY()));	
	res.append("), ");
	res.append(to_string(radius));
	return res;
}


ostream& operator<< (ostream & s, Circle& c){
	Point p = c.getCentre();
	double r = c.getRadius();
	return s << "<(" << p.getX() << ", " << p.getY() << "), " << r << ">" << endl;
}

istream& operator >> (istream & in, Circle &c){
	//str.read(in);
	return in;
}

