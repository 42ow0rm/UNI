// Datei Position.cpp
#include "Position.hpp"
#include "Labyrinth.hpp"

// Hilfsfunktion max
int max(int x, int y) {
	return (x <= y) ? y : x;
}
// Hilfsfunktion min
int min(int x, int y) {
	return (x <= y) ? x : y;
}
// Konstruktor
Position::Position(int x, int y) {
	posx = x;
	posy = y;
}
// Schritt nach vorne in Richtung r um einen Schritt
// Es kann aber nicht in Mauern hineingelaufen werden
// *this wird entsprechend geändert
// Der int mode = 0 gibt an, dass die Mauern berücksichtigt werden.
// Wenn int != 0, dann kann auch durch Mauern gelaufen werden.
// Dies ist für das Erstellen von Labyrinthen notwendig.
Position & Position::schritt(Labyrinth & lab, int mode) {
	Position tmp = *this;
	switch (r) {
		// oben
	case Richtung::OBEN: tmp.posy = max(1, posy - 1); break;
		// links
	case Richtung::LINKS: tmp.posx = max(1, posx - 1); break;
		// rechts
	case Richtung::RECHTS: tmp.posx =
		min(lab.getSpalten() - 2, posx + 1);
		break;
		// unten
	case Richtung::UNTEN: tmp.posy =
		min(lab.getZeilen() - 2, posy + 1);
		break;
	}
	if (mode != 0 || lab.getZeichenAnPos(tmp) != MAUER) {
		*this = tmp;
	}
	return *this;
}
// Zwei Positionen vergleichen,
// liefert true, wenn x und y gleich
bool Position::istGleichZu(Position & p) {
	return (posx == p.posx && posy == p.posy);
}
