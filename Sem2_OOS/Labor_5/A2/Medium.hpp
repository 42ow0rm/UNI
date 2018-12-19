// Medium.hpp
#pragma once

#include <string>
#include "Datum.hpp"
#include "Person.hpp"
#include <iomanip>
using namespace std;

// Klasse für die Medien, die in der Bibliothek ausgeliehen werden 
// können
class Medium {
	// Titel des Mediums
	const string titel;
	// Verlag, der das Medium herausgibt
	const string verlag;
	// Jahr, in dem das Medium veröffentlicht wurde
	const int jahr;
	// ausgeliehen von
	Person * ausleiher;
	// ausgeliehen am 
	Datum von;
	// ausgeliehen bis
	Datum bis;

public:
	// Konstruktor
	Medium(string t = "", string v = "", int j = 0) : titel(t), verlag(v), jahr(j) {
		ausleiher = nullptr;
	};
	// Titel zurückliefern
	string getTitel() const;
	// Ausleiher zurückliefern
	Person * getAusleiher() const;
	// das Mediuem "ausleihen", d.h. Person p, von und bis eintragen
	void ausleihen(Person & p, Datum von, Datum bis);
	// Medium in der Konsole ausgeben
	virtual void print() const = 0;
};
