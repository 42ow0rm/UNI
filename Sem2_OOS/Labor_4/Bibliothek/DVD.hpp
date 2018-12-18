// DVD.hpp
#pragma once

#include "Medium.hpp"

// Klasse für die DVDs als Spezialisierung von Medium
class DVD : public Medium{
	// Abspieldauer der DVD
	const int dauer;
public:
	// Standardkonstruktor
	DVD(string t = "", string v = "", int j = 0, int d = 0) : Medium(t, v, j, "DvD"), dauer(d) {};
	// die DVD auf der Konsole ausgeben
	void print() const {
		Medium::print();
		cout << "Dauer:\t\t" << dauer << endl;
	};
};
