#include <iostream>
#include "Circle.hpp"
#include "Polygonline.hpp"
using namespace std;

void parseString(string str){
	str = removeCharFromString(str, ' ');
	int end_pos = 1;
	
	if (str.at(0) == '|'){ //Polyl
		
		string pl;
		string delimiter = "-";
		//str = removeCharFromString(str, '(');
		//str = removeCharFromString(str, ')');
		while (str.at(end_pos) != '|'){
			end_pos++;
		}	
		for(size_t i = 0; i < end_pos; ++i)
			pl += str[i];
			
		pl = removeCharFromString(pl, '|');	
		//cout << pt;
		
		size_t pos = 0;
		string token;
		while ((pos = pl.find(delimiter)) != string::npos) {
		    token = pl.substr(0, pos);
		    //cout << token;
		    parseString(token);
		    pl.erase(0, pos + delimiter.length());
		}
		parseString(pl);
		
	}else if (str.at(0) == '<'){ //Circle
		
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
		cout << x << endl << y << endl << r << endl;	
		
	}else if (str.at(0) == '('){ //Point
		
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
		cout << x << endl << y << endl;	
	}

	
	
	
	
	

}

// Hauptprogramm
int main(void)
{
	Point p1(0, 0);
	const Point p2(2, 2);
	const Point p3(3, 3);
	Circle c(p1, 1.1);
	cout << "Circle:" << c << endl;
	p1 = p1 + 0.5;
	p1 = 0.5 + p1;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	Point p4 = p1 + p2 - p3 + 4.0;
	cout << "p4: " << p4 << endl;
	p1 = -p4;
	cout << "p1: " << p1 << endl;
	cout << "p4: " << p4 << endl;
	Point p5 = p1++;
	cout << "p5: " << p5 << endl;
	cout << "p1: " << p1 << endl;
	p5 = ++++++++p1;
	cout << "p5: " << p5 << endl;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	cout << "p4: " << p4 << endl;
	Polygonline l1;
	cout << "l1: " << l1 << endl;
	(l1 + p1) + p2;
	cout << "l1 :" << l1 << endl;
	const Polygonline l2(p4);
	l1 + l2;
	cout << "l1 :" << l1 << endl;
	cout << "l2 :" << l2 << endl;
	return 0;
}
