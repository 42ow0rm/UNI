#include "Person.hpp"

string Person::getName() const{
	return name;
}

int Person::getAusleihdauer() const {
	return ausleihdauer;
}

void Person::print() const{
	cout << "Ausleiher:\t";
	if (getAusleihdauer() == 0) {
		cout << "kein" << endl;
	}
	else {
		cout << getName() << "\nDauer\t" << getAusleihdauer() << endl;
	}
}