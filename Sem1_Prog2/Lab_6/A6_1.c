#include "stdafx.h"



int Eingabe(FILE *fptr) {

	int num, isEndOfInput;
	int Anzahl = 1;

	fopen_s(&fptr, "C:\\Users\\Hendr\\Desktop\\Blatt 6.txt", "w");						//Datei wird geöffnet und beschrieben

	if (fptr != NULL) {
		printf("Datei wurde erfolgreich erstellt!\n\n");								//Abfrage ob Datei öffnen geklappt hat
	}
	else {
		printf("Datei konnte nicht erstellt werden.\n");
		return 0;
	}

	printf("beliebig viele Integerzahlen eingeben. [nicht-Integer eingabe fuer Ende]: \n\n");	//Konsolenausgabe
	printf("1.te Zahl: ");

	while (1) {
		Anzahl++;
		isEndOfInput = scanf_s("%d", &num);			//Zahleingabe		
		if (isEndOfInput != 0) {					//Wahrhreit, Wenn Zahl eingegeben wurde 
			fprintf(fptr, "%d\n", num);				//Zahl wird in Datei geschrieben
			printf("%d.te Zahl: ", Anzahl);
		}
		else {
			break;									//Wenn keine int Zahl, dann abbruch von While
		}
	}

	fclose(fptr);									//Datei schließen
	fptr = NULL;									//
	return 0;
}

int Ausgabe(FILE *fptr) {

	int num, i = 0;
	float Durchschnitt = 0;

 fopen_s(&fptr, "C:\\Users\\Hendr\\Desktop\\Blatt 6.txt", "r");			//Datei wird geöffnet und gelesen

	if (fptr != NULL) {																	//Check ob Datei erfolgreich geöffnet wurde
		printf("\nDatei wurde erfolgreich geoeffnet!\n\n");
	}
	else {
		printf("\nDatei konnte nicht goeffnet werden.\n");
		return 1;
	}
	printf("\nDer Durchschnitt aller eingegebenen Zahlen war folgender:\n");
	while (fscanf_s(fptr, "%d", &num) != EOF) {					//Datei wird ausgelesen und in num gespeichert, bis End of File erreicht wird
		Durchschnitt += num;										//Zahlen werden aufsummiert
		i++;														//Anzahl der Zahlen werden gezählt
	}

	Durchschnitt = Durchschnitt / i;							//Summe wird durch Anzahl geteilt
	printf("\n%f\n", Durchschnitt);								//Konsolenausgabe
	fclose(fptr);												//Datei wird geschlossen

	return 0;

}


int main(void) {

	FILE *fptr = NULL;
	int isError = 0;

	isError = Eingabe(fptr);				//Aufruf von Funktion Eingabe(Pointer)
	if (isError) {						//Abfrage ob Eingabe geklappt hat
		printf("ein Fehler ist aufgetreten, Programm wird geschlossen.");
		isError = 0;				//für späteren Verlauf wieder auf 0 setzen
		return -1;					//Abbruch
	}

	isError = Ausgabe(fptr);									//Aufruf von Funktion Ausgabe(Pointer)
	if (isError) {												//Abfrage ob Ausgabe geklappt hat
		printf("ein Fehler ist aufgetreten, Programm wird geschlossen.");
		return -1;
	}

	system("pause");

	return 0;
}
