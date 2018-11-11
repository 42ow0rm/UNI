

// Datei Position.hpp
#pragma once
// Vorwärtsdeklaration der Klasse Labyrinth
class Labyrinth;
// Die Laufrichtung (Orientierung) als Aufzählungstypen
enum Richtung { RECHTS, LINKS, OBEN, UNTEN };
// Klasse Position
// Speichert die Position (x,y) und Laufrichtung eines Objektes
// im Labyrinth
// Als struct realisiert, damit später direkt auf posx und posy
// zugegriffen werden kann.
struct Position {
	// Position in den Spalten
	int posx;
	// Position in den Zeilen
	int posy;
	// Richtung, in die jemand orientiert ist
	Richtung r;
	// Konstruktor mit posx (Spalten) und posy (Zeilen)
	Position(int = 0, int = 0);
	// Schritt nach vorne in Richtung r um einen Schritt
	// *this wird entsprechend geändert
	// Der int = 0 gibt an, dass die Mauern berücksichtigt werden.
	// Wenn int != 0, dann kann auch durch Mauern gelaufen werden.
	// Dies ist für das Erstellen von Labyrinthen notwendig.
	Position & schritt(Labyrinth &, int = 0);
	// Zwei Positionen vergleichen,
	// liefert true, wenn x und y gleich
	bool istGleichZu(Position &);
};
