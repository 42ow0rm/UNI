/* Labor 3 , Aufgabe 3_4
Erstersteller: Hendrik Duller
Datum: 30.05.2018
Version: 01
Change History:
---------------
Aenderungsgrund durchgefuehrte Aenderung Autor Datum
--------------------------------------------------------
Programmbeschreibung:
Zeichenketten mithilfe von Pointern und Verktoren kopieren
Eingabeparameter:
-----------------------------
Ausgabeparameter:
-----------------------------
Fehlerausgänge:
---------------
*/

#include "stdafx.h"
#include "stdio.h"


void strcpy1(char d[], char s[])
{
	int i = 0;
	do {
		d[i] = s[i];
			i++;
	} while ( s[i] != '\0');
}

void strcpy2(char * d, char * s)
{
	do {
		*s = *d;
			s++;
		d++;
	} while ( *d != '\0' );
}

int main()
{
	char donuts[80];
	char bufneu[80] = "Die Sonnenbrille schützt meine Identität!";
	char buffer[80] = "How do you do?";
	printf("Bitte einen Satz eingeben, welcher kleiner ist als 80 Zeichen:\n");
	gets(donuts);
	printf("Hier kommt erster Satz: %s\n", bufneu);
	printf("Hier kommt zweiter Satz: %s\n", buffer);
	strcpy1(bufneu, donuts);
	printf("\n Inhalt des Puffers bufneu nach ");
	printf("strcpy1 (bufneu, text): %s\n", bufneu);
	printf("\n In Puffer buffer steht: %s\n", buffer);
	strcpy2(bufneu, buffer);
	printf("\n Inhalt des Puffers bufneu nach ");
	printf("strcpy2 (bufneu, buffer): %s\n", bufneu);

	system("pause");
    return 0;
}

