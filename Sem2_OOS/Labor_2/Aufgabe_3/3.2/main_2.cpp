#include <iostream>
#include "Polygonline.hpp"
using namespace std;

// Hauptprogramm
int main(void)
{
	Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
	Polygonline l1; 
	Polygonline l2(p3);
	cout << "Ausgabe 1:" << endl;
	l1.toString();
	l2.toString();
	l1.addPoint(p1).addPoint(p2);
	l2.addPoint(p4).addPoint(p5);
	cout << "Ausgabe 2:" << endl;
	l1.toString();
	l2.toString();
	p2.move(0.5,0.5);
	cout << "Ausgabe 3:" << endl;
	p2.toString();
	l1.toString();
	l2.toString();
	l1.appendPolygonline(l2);
	cout << "Ausgabe 4:" << endl;
	l1.toString();
	l2.toString();
	l1.move(0, 0.5);
	cout << "Ausgabe 5:" << endl;
	l1.toString();
	l2.toString();
	return 0;
}
