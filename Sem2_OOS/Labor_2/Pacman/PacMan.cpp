// Datei PacMan.cpp
#include <windows.h>
#include <conio.h>
// conio.h für _getch() und _kbhit()
// Achtung: Nicht Teil des Standards und daher abhängig vom Compiler
#include <iostream>
#include "PacMan.hpp"

using namespace std;

// Konstruktor
PacMan::PacMan(Labyrinth & l, Spieler & sp, Spieler gArr[],
	int anzGeister) {
	schritte = 0; // Anzahl der Spielschritte
	muenzen = 0; // Anzahl der Münzen im Labyrinth
	lab = &l;
	s = &sp;
	for (int i = 0; i < anzGeister; i++) {
		g[i] = &gArr[i];
	}
	// Spieler in die Mitte des Labyrinths setzen
	Position zentrum(lab->getSpalten() / 2, lab->getZeilen() / 2);
	s->setPos(zentrum);
	// Anzahl der Münzen vom Labyrinth übernehmen
	muenzen = lab->getMuenzen();
}
// Einen Schritt im Spiel ausführen
void PacMan::schritt() {
	// Schritte zählen
	schritte++;
	// Aktuelle Position des Spielers merken,
	// so dass sie mit WEG überschrieben werden kann.
	Position postmp = s->getPos();
	// Den Spieler einen Schritt machen lassen.
	s->schritt(*lab);
	// Wenn beim neuen Schritt eine Münze gefunden wurde ...
	if (lab->istMuenzeAnPos(s->getPos())) {
		// Anzahl der gesammelten Münzen des Spielers erhöhen
		s->plusMuenze();
		// Anzahl der vorhandenen Münzen reduzieren
		muenzen--;
	}
	// den getanen Schritt des Spielers einzeichnen
	lab->zeichneChar(WEG, postmp, s->getPos());
	lab->zeichneChar(ICH, s->getPos());
	// Dem Spieler 5 Schritte Vorsprung vor den Geistern lassen
	if (schritte == 5) {
		Position zentrum(lab->getSpalten() / 2, lab->getZeilen() / 2);
		for (int i = 0; i < kAnzGeister; i++) {
			g[i]->setPos(zentrum);
			lab->zeichneChar(GEIST, g[i]->getPos());
		}
	}
	// Jetzt laufen die Geister
	if (schritte > 5) {
		for (int i = 0; i < kAnzGeister; i++) {
			// Geist-Zeichen löschen
			lab->zeichneChar(WEG, g[i]->getPos());
			// Geist wählt zufällig seine Schrittrichtung
			g[i]->orientieren(*lab);
			// Geist macht seinen Schritt
			g[i]->schritt(*lab);
		}
		// Geister einzeichnen
		for (int i = 0; i < kAnzGeister; i++) {
			// Geister sammeln Münzen
			if (lab->istMuenzeAnPos(g[i]->getPos())) {
				// Anzahl der vorhandenen Münzen reduzieren
				muenzen--;
			}
			// Geist einzeichnen
			lab->zeichneChar(GEIST, g[i]->getPos());
		}
	}
}
// Spiel spielen
void PacMan::spielen() {
	// Das Spiel läuft solange noch Münzen im Labyrinth sind
	// und eine Geist nicht auf der Position des Spielers ist.
	// Temporäre Variable für die Keyboard-Eingabe
	char c = 'x';
	// Temporäre Variable, um die gewählte Richtung zu speichern
	Richtung r = s->getPos().r;
	// Position des Spielers einzeichnen
	lab->zeichneChar(ICH, s->getPos());
	// Temporäre Variable für die Abbruchbedingung der Spielschleife
	bool cond = (muenzen > 1);
	while (cond) {
		// Eine Weile warten (Windows)
		Sleep(700);
		// Eine Weile warten (C++11)
		// std::this_thread::sleep_for(std::chrono::milliseconds(700));
		if (_kbhit()) { // wenn Taste gedrückt wurde ...
			c = _getch();
			switch (int(c)) {
				// oben
			case 72: r = OBEN; break;
				// links
			case 75: r = LINKS; break;
				// rechts
			case 77: r = RECHTS; break;
				// unten
			case 80: r = UNTEN; break;
				// q = quit
			case 113: muenzen = 0; break;
			}
			s->setRichtung(r);
		}
		// Einen Spielschritt ausführen
		schritt();
		// Neue Spielsituation anzeigen
		lab->drucken();
		cout << "Gesammelte Muenzen: " << s->getMuenzen() << endl;
		cout << "Verbleibende Muenzen: " << muenzen << endl;
		cout << schritte << ". Schritt" << endl << endl;
		cout << "Zum Abbrechen q druecken" << endl;
		// Prüfen, ob noch Münzen da sind
		// und ob der Spieler noch nicht gefangen wurde
		cond = (muenzen > 1);
		for (int i = 0; i < kAnzGeister; i++) {
			cond = cond && !(s->getPos().istGleichZu(g[i]->getPos()));
		}
	}
}
