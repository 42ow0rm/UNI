#include "Bibliothek.hpp"

Bibliothek::~Bibliothek() {
	delete[] medien;
}

void Bibliothek::mediumBeschaffen(Medium & m) {
	Medium * medium = &m;
	medien[anz++] = medium;
}

void Bibliothek::mediumSuchen(string suchwort) {
	cout << "\nSuche nach \"" << suchwort << "\". Ergebnis:" << endl;
	for (int n = 0;n < anz; n++) {
		if (medien[n]->getTitel().find(suchwort, 0) != string::npos)
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
		medien[n]->print();
	}
};