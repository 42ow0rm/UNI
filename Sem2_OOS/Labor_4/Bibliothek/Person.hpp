// Person.hpp
#pragma once

#include <string>
#include <iostream>
using namespace std;

// Klasse für alle Personen, die Medien ausleihen können
class Person {
	// Name der Person
	string name;
	// Dauer in Tagen, die die Person ein Medium ausleihen darf
	// wird von den abgelieteten Klassen festgelegt
	int ausleihdauer;
public:
	// Standardkonstruktor
	Person(string name = "keine", int dauer = 0) {
		this->name = name;
		ausleihdauer = dauer;
	};
	// den Namen zurückliefern
	string getName() const;
	// die Ausliehdauer zurückliefern
	int getAusleihdauer() const;
	// die Person auf der Konsole ausgeben
	void print() const;
};


