#include <iostream>
#include "Circle.hpp"
#include "Polygonline.hpp"
using namespace std;

bool debugConstructor = true;

unsigned int ObjectCounter::maxId = 0;
unsigned int ObjectCounter::number = 0;

// Hauptprogramm
int main(void)
{
	cout << "Anzahl der Objekte: " << DrawingObject::getNumber();
	cout << endl;
	Point p1;
	cout << "p1 ObjectId: " << p1.getId() << " " << p1 << endl;
	Point p2(1,1);
	cout << "p2 ObjectId: " << p2.getId() << " " << p2 << endl;
	Circle c1(p1,3);
	cout << "c1 ObjectId: " << c1.getId() << " " << c1 << endl;
	Polygonline l1(p1);
	cout << "l1 ObjectId: " << l1.getId() << " " << l1 << endl;
	cout << "Anzahl der Objekte: " << c1.getNumber() << endl;
}
