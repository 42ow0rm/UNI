#include <iostream>
#include "MyList.hpp"
#include "Circle.hpp"
using namespace std;

int main() {
	Point p1(1,1);
	Point p2(2,2);
	Point p3(3,3);
	Point p4(4,4);
	cout << "Liste v1 erstellen ..." << endl;
	MyList v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	cout << "Liste v1 ausgeben ..." << endl;
	v1.print();
	cout << "Liste v1 in v2 kopieren ..." << endl;
	MyList v2(v1);
	cout << "Liste v2 ausgeben ..." << endl;
	v2.print();
	cout << "Punkt am Beginn der Liste v2 verschieben ..." << endl;
	dynamic_cast<Point&>(v2.front()).move(10,10);
	cout << "Liste v1 ausgeben ..." << endl;
	v1.print();
	cout << "Liste v2 ausgeben ..." << endl;
	v2.print();
	cout << "Groesse von v1: " << v1.size() << endl;
	if (!v1.empty()) {
		v1.clear();
	}
	cout << "Groesse von v1: " << v1.size() << endl;
	v1.print();
	v2.print();
	cout << "Groesse von v2: " << v2.size() << endl;
	v2.push_back(p1);
	cout << "Groesse von v2: " << v2.size() << endl;
	v2.print();
	cout << "Punkt (4,4) hinten an v1 anhaengen ..." << endl;
	v1.push_back(p4);
	cout << "Liste v1 an v2 anhaengen ..." << endl;
	v2 = v2+v1;
	cout << "Liste v1 ausgeben ..." << endl;
	v1.print();
	cout << "Liste v2 ausgeben ..." << endl;
	v2.print();
	cout << "Liste mit Kreisen ..." << endl;
	Circle c1(p1, 1);
	Circle c2(p2, 2);
	MyList v3;
	v3.push_back(c1);
	v3.push_back(c2);
	v3.print();

	getchar();
	return 0;
}
