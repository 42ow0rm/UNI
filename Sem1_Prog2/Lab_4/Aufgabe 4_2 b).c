#include "stdafx.h"
#include "stdio.h"
#include <math.h>

float reihe(int *);
void einlesen(int *);


int main() {
	int Anzahl = 0;
	float Ergebnis;

	printf("Geben sie bitte eine Ganzzahlige Zahl ein: ");
	einlesen(&Anzahl);
	Ergebnis = reihe(&Anzahl);
	printf("Dein Ergebnis: %f\n", &Ergebnis);
	system("PAUSE");
	return 0;
}

float reihe(int *Anzahl) {
	float Ergebnis = 1.0;
	int i = 2;
	
	if (Anzahl == 1) {
		return 1.0;
	}

		if (!(Anzahl % 2)) {

			return -1.0/(float)Anzahl + reihe(--Anzahl);

		}
		else
			return 1.0 / (float)Anzahl + reihe(--Anzahl);


	return Ergebnis;
}

void einlesen(int * var) {

	int check;
	check = scanf_s("%i", var);
	if (!check) {
		fflush(stdin);
		printf("Ungueltige Eingabe! Bitte wiederholen.\n");
		exit(1);
	}

}
