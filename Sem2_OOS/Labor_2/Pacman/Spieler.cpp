#include <iostream>
#include "Spieler.hpp"
#include "MyString.hpp"
#include "Labyrinth.hpp"
//#include "PacMan.hpp"
#include "Position.hpp"

using namespace std;

Spieler::Spieler(MyString name){
	this->name = name;
}

Spieler::Spieler(char *Ar) {
	this->name = MyString(Ar);
}

Position &Spieler::getPos() {
	return this->pos;
}

void Spieler::setPos(Position &pos) {
	this->pos = pos;
}

void Spieler::setRichtung(Richtung &dir) {			//
	this->pos.r = dir;
}

int Spieler::getMuenzen() {
	return this->muenzen;
}

void Spieler::plusMuenze() {
	this->muenzen += 1;
}

Spieler & Spieler::schritt(Labyrinth &Lab_) {
	this->pos.schritt(Lab_);
	return *this;
}

// Schrittrichtung automatisch wählen lassen
void Spieler::orientieren(Labyrinth &lab) {
	Position postmp = pos;
	// Eine von 4 Richtungen auswählen
	int rint = rand() % 4;
	postmp.r = Richtung(rint);
	while ((lab.getZeichenAnPos(postmp)) == MAUER) {
		rint = rand() % 4;
		postmp.r = Richtung(rint);
	}
	pos.r = Richtung(rint);
}

