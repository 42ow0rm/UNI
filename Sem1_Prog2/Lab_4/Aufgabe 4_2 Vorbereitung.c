#include "stdafx.h"
#include "stdio.h"
#include <math.h>

float reihe_iterativ(int );
float reihe_rekursiv(int );
void einlesen(int *);


int main(){
	int Anzahl = 0;
	float Ergebnis;

	printf("Geben sie bitte eine Ganzzahlige Zahl ein: ");
	einlesen(&Anzahl);
	printf("Dein iterativ berechnetes Ergebnis: %f\n", reihe_iterativ(Anzahl));
	printf("Dein rekursiv berechnetes Ergebnis: %f\n", reihe_rekursiv(Anzahl));
	system("PAUSE");
    return 0;
}

float reihe_iterativ(int Anzahl) {
	float Ergebnis = 1.0;

	for (int i = 2 ; i <= Anzahl; i++) {

		if (i % 2 == 0) {

			Ergebnis = Ergebnis - (1.0 / (float)i);

		}
		else
		Ergebnis = Ergebnis + (1.0 / (float)i);

	}


	return Ergebnis;
}

float reihe_rekursiv(int Anzahl) {
	
	if (Anzahl == 1) {
		return (float)1;
	}
		if (Anzahl % 2 == 0) {

			return   reihe_rekursiv(Anzahl - 1) - (1.0 / (float)Anzahl);

		}
		else
			return  (1.0 / (float)Anzahl) + reihe_rekursiv(Anzahl - 1);


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
