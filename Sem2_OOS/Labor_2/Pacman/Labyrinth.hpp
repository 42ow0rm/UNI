#pragma once
#include "Position.hpp"
#include <iostream>

using namespace std;

struct Position;
const int kSpalten = 11;
const int kZeilen = 11;
const int kAnzGeister = 3;

enum Symbole {
	MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n',
	EOS = '\0', ICH = 'X', GEIST = 'G'
};

class Labyrinth {
private:
	int labSpalten;
	int labZeilen;
	int labAnzGeister;
	char lab[kZeilen][kSpalten + 2];
	int muenzen;

public:
	Labyrinth();
	void initialisieren();
	void drucken();
	void erzeugen();

	//void setSpalten(int labSpalten);
	//void setZeilen(int labZeilen);
	//void setAnzGeister(int labAnzGeister);
	int getSpalten();
	int getZeilen();
	int getAnzGeister();
	int getMuenzen();
	int legeMuenzen();

	void zeichneChar(char c, Position pos);
	void zeichneChar(char c, Position posalt, Position posneu);

	char getZeichenAnPos(Position pos);
	bool istMuenzeAnPos(Position pos);

	void exportDatei(char *dateiname);
	void importDatei(char *dateiname);
};
