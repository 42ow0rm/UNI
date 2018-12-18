#include "Bibliothek.hpp"

Bibliothek::~Bibliothek() {
	delete[] medien;
}

void Bibliothek::mediumBeschaffen(Buch & b) {
	Medium * medium = &b;
	medien[anz++] = medium;
}
void Bibliothek::mediumBeschaffen(DVD & d) {
	Medium * medium = &d;
	medien[anz++] = medium;
};

void Bibliothek::mediumSuchen(string suchwort) {
	cout << "\nSuche nach \"" << suchwort << "\". Ergebnis:" << endl;
	for (int n = 0;n < anz; n++) {
		if (medien[n]->getTitel().find(suchwort, 0) != string::npos ||
			medien[n]->getTyp().find(suchwort, 0) != string::npos)
		{
			cout << "\nMedium " << n << ":" << endl;
			medien[n]->print();
		}
		else {

		}
	}
};

void Bibliothek::print() const {
	cout << "\nBibliothekskatalog:" << endl;
	for (int n = 0; n < anz; n++) {
		if (medien[n]->getTyp() == "Buch"){
			Buch * b = (Buch *)medien[n];
			b->print();
		}
		else
		{
			DVD * d = (DVD *)medien[n];
			d->print();
		}
	}
};