// Main für Hausaufgabe 2
#include "Labyrinth.hpp"
int main() {
	Labyrinth lab;
	lab.drucken();
	lab.erzeugen();
	lab.drucken();
	lab.exportDatei((char *)"lab.txt");
	Labyrinth lab2;
	lab2.importDatei((char *)"lab.txt");
	lab2.drucken();
	lab2.legeMuenzen();
	lab2.drucken();
}
