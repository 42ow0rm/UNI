#include <iostream>
#include <sstream>
#include "Circle.hpp"
#include "Polygonline.hpp"
#include "Rectangle.hpp"
using namespace std;

bool debugConstructor = true;

unsigned int ObjectCounter::maxId = 0;
unsigned int ObjectCounter::number = 0;

// Hauptprogramm
int main(void)
{
	DrawingObject * objects[20];
	int anzahl = 0;
	int i = 0;
	cout << "Wieviele Objekte wollen Sie einlesen?" << endl;
	cout << "Anzahl: ";
	cin >> anzahl;
	// anzahl = (anzahl > 20 ? 20 : anzahl);
	
	// Objekte einlesen
	//int anz_max = atof(anzahl);
	cout << anzahl << endl;
	for (i=0; i<anzahl; i++)
	{
		cout << "Bitte Objektstring eingeben: ";
		string in;
		//cin.clear(); //->MS Visual Studio
		cin.ignore(10000, '\n'); //-> dev-cpp
		getline(cin, in);
		// cin >> in;
		DrawingObject *d = nullptr;
		switch (in.c_str()[0])
		{
			case '(': {
				d = new Point(in);
				break;
			}

			case '<': {
				d = new Circle(in);
				break;
			}

			case '|': {
				d = new Polygonline(in);
				break;
			}
			
			case '[': {
				d = new Rectangle(in);
				break;
			}

			default:
				cout << "ungültige Eingabe - '" << in << "'" << endl;
				exit(0);
		}
		//	einzelnes Objekt einlesen
		objects[i] = d;
	}
	
	// Objekte ausgeben
	for (i=0; i<anzahl; i++)
	{
		if (objects[i])
			objects[i]->print(); // einzelnes Objekt ausgeben
	}
	
	return 0;
}


//test 
//[(1,1), (2,2)]
