#include <iostream>
#include <conio.h>			//stand in Labor 1 datei (fuer getline_)
#include <fstream>
#include "Labyrinth.hpp"
//#include "Position.hpp"

using namespace std;

extern int max(int, int);
extern int min(int, int);

// Zeichen, die im Labyrinth vorkommen können,
// NL = new line, EOS = end of string
/*enum Symbole {
	MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n',
	EOS = '\0', ICH = 'X', GEIST = 'G'
};*/

Labyrinth::Labyrinth() {
	Labyrinth::labSpalten = kSpalten;
	Labyrinth::labZeilen = kZeilen;
	Labyrinth::labAnzGeister = kAnzGeister;
	Labyrinth::muenzen = 0;
	initialisieren();
}

void Labyrinth::initialisieren() {
	for (int i = 0; i < kZeilen; i++) {
		for (int k = 0; k < kSpalten; k++) {
			lab[i][k] = MAUER;
		}
		lab[i][kSpalten] = NL;
		lab[i][kSpalten + 1] = EOS;
	}
}

// Labyrinth auf dem Bildschirm ausgeben
void Labyrinth::drucken() {
	// Console frei machen
	system("cls");
	// Labyrinth ausgeben
	for (int l = 0; l < kZeilen; l++) {
		cout << lab[0 + l];
	}
}

void Labyrinth::erzeugen() {
	char c = 'x';
	int posx = kSpalten / 2;
	int posy = kZeilen / 2;
	lab[posy][posx] = ICH;
	drucken();
	while (c != 'q') {
		drucken();
		cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;
		lab[posy][posx] = WEG;
		c = _getch();
		switch (int(c)) {
			// oben
		case 72: posy = max(1, posy - 1); break;
			// links
		case 75: posx = max(1, posx - 1); break;
			// rechts
		case 77: posx = min(kSpalten - 2, posx + 1); break;
			// unten
		case 80: posy = min(kZeilen - 2, posy + 1); break;
			// q = quit
		case 113: break;
		}
		lab[posy][posx] = ICH;
	}
}

int Labyrinth::getZeilen() {
	return labZeilen;
}

int Labyrinth::getSpalten() {
	return labSpalten;
}

int Labyrinth::getAnzGeister() {
	return labAnzGeister;
}

int Labyrinth::getMuenzen() {
	return muenzen;
}

int Labyrinth::legeMuenzen() {
	int AnzahlMuenzen = 0;
	for (int i = 0; i < kSpalten; i++) {
		for (int k = 0; k < kZeilen; k++) {
			if (lab[i][k] == WEG) {
				lab[i][k] = MUENZE;
				AnzahlMuenzen = AnzahlMuenzen + 1;
			}
		}

	}
	return AnzahlMuenzen;
}

void Labyrinth::zeichneChar(char c, Position pos) {
	this->lab[pos.posy][pos.posx] = c;
}

void Labyrinth::zeichneChar(char c, Position posalt, Position posneu) {
	this->zeichneChar(c, posneu);
	this->zeichneChar(WEG, posalt);
}

char Labyrinth::getZeichenAnPos(Position pos) {
	return lab[pos.posy][pos.posx];
}

bool Labyrinth::istMuenzeAnPos(Position pos) {
	if (lab[pos.posy][pos.posx] == MUENZE) {
		return true;
	}
	else return false;
}

// Labyrinth als Textdatei speichern
void Labyrinth::exportDatei(char * dateiname) {
	ofstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei << lab[i];
	}
	datei.close();
}
// Labyrinth als Textdatei einlesen
void Labyrinth::importDatei(char * dateiname) {
	ifstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei.getline(lab[i], kSpalten + 2);
		lab[i][kSpalten] = NL;
		lab[i][kSpalten + 1] = EOS;
	}
	datei.close();
}
