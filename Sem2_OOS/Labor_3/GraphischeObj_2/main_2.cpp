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
	string s1 ("(1.1,2.1) ist ein Punkt");
	//parseString(s1);
	Point p(s1);
	cout << p << endl;
	
	string s2 ("<(5.5,6.6), 10.1> ist ein Kreis");
	//parseString(s2);
	Circle c(s2);
	cout << c << endl;
	
	string s3 ("|(1.1, 1.2) - (2.1, 2.2) - (3.1, 3.2)| ist ein Polyline");
	//parseString(s3);
	Polygonline l(s3);
	cout << l << endl;

	cout << p.toString() << endl;
	cout << c.toString() << endl;
	c.move(1.0, 2.0);
	cout << c.toString() << endl;
	cout << l.toString() << endl;
	return 0;
}
