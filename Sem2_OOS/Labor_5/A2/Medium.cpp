#include "Medium.hpp"

string Medium::getTitel() const{
	return titel;
}

Person * Medium::getAusleiher() const {
	return ausleiher;
};

void Medium::ausleihen(Person & p, Datum von, Datum bis) {
	ausleiher = &p;
	this->von = von;
	this->bis = bis;
};

void Medium::print() const {
	cout << "Titel:\t\t" << titel << endl;
	cout << "Verlag:\t\t" << verlag << endl;
	cout << "Jahr:\t\t" << jahr << endl;
	cout << "Ausleiher:\t";
	if (ausleiher == nullptr) cout << "keine"<< endl;
	else {
		cout << ausleiher->getName() <<"von: " << von << " bis: " << bis << endl;
	}
};