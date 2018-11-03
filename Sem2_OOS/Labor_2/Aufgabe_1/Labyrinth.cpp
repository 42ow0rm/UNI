#include <iostream>
#include <conio.h> // für _getch()
// Achtung: _getch() ist nicht im Standard und 
//          daher abhängig vom Compiler
#include "Labyrinth.hpp"

using namespace std;

// Konstruktor
Labyrinth::Labyrinth() {
	
	// Größe des Labyrinths
	const int kZeilen = 11;
	const int kSpalten = 11;

	// Zeichen, die im Labyrinth vorkommen können,
	// NL = new line, EOS = end of string
	enum Symbole { MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n', 
	           EOS = '\0', ICH = 'X', GEIST = 'G' };

	// Das Labyrinth als char-Array
	// Die vorletzte Spalte speichert ein Zeilenendezeichen \n
	// und die letzte ein \0-Zeichen, damit die Ausgabe leichter wird.
	char labyrinth[kZeilen][kSpalten + 2];
	
}

// Labyrinth mit # füllen
void Labyrinth::initialisieren() {
	for (int i = 1; i < kZeilen; i++) {
		for (int j = 1; j < kSpalten; j++) {

			labyrinth[i][j] = '#';

		}
		labyrinth[i][kSpalten + 1] = '\n';
		labyrinth[i][kSpalten + 2] = '\0';
	}
}

// Labyrinth auf dem Bildschirm ausgeben
void Labyrinth::drucken() {
	// Console frei machen
	system("cls");
	// Labyrinth ausgeben
	for (int i = 1; i < kZeilen; i++) {
		for (int j = 1; j < (kSpalten + 2); j++) {

			cout << labyrinth[i][j];

		}
	}
}
