/* Labor 3 , Aufgabe 3_5 
Erstersteller: Hendrik Duller
Datum: 12.06.2018
Version: 01
Change History:
---------------
Aenderungsgrund durchgefuehrte Aenderung Autor Datum
--------------------------------------------------------
Programmbeschreibung:
Ausgeben von eingebenen Zahlen
Eingabeparameter:
-----------------------------
Ausgabeparameter:
-----------------------------
Fehlerausgänge:
---------------
*/


#include "stdafx.h"
#include "stdio.h"

void einlesen(int * var);

int main(void) {
	int ar[11];
	int i;
	for (i = 1; i <= sizeof(ar) / 4; i++) {
		printf("Bitte die %i. Zahl eingeben: ", i);
		einlesen(&ar[i]);
		
	}
	printf("Eingegebene Zahlen:\n");
	for (i = 1; i <= sizeof(ar) / 4; i++) {
		printf("%i\t", ar[i]);
		if (i % 5 == 4) {
			printf("\n");
		}
	}
	printf("\n");

	system("pause");

}

void einlesen(int * var) {
	
	int check;
	check = scanf_s("%i", var);
	if (!check) {
		fflush(stdin);
		printf("Ungueltige Eingabe! Bitte wiederholen.\n");
	}
	
}