// Student.hpp
#pragma once

#include "Person.hpp"

// Klasse Student als Spezialisierung von Person
class Student : public Person {
	// Matrikelnummer des Studenten/der Studentin
	int matNr;
public:
	// Standardkonstruktor
	Student(string name, int matNr) : Person(name), matNr(matNr) {};
	// Student auf der Konsole ausgeben
	void print() const {
		cout << Person::getName();
	};
};
