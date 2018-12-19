// Datum.hpp
#pragma once

#include <string>
#include <sstream>
using namespace std;

// Klasse Datum, ähnlich zu der in der Übung der Vorlesung
class Datum {
	// Elemente eines Datums
	int tag, monat, jahr;




public:
	// Standardkonstruktor
	Datum(int = 0, int = 0, int = 0);
	// Konvertierkonstruktor für String
	Datum(const string &);
	// Konvertierkonstruktor für C-String
	Datum(const char *);
	// Operator + addiert eine Anzahl von Tagen zum Datum hinzu
	Datum operator+(int tage);
	// Ausgabeoperator <<, Ausgabe in dem Format tt.mm.jjjj
	friend ostream & operator<<(ostream &, const Datum &);
};


