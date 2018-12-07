#include <stdio.h>

int Eingabe(FILE *fptr) {
	int num, isEndOfInput;
	int Anzahl = 1;
	fopen_s(&fptr, "C:\\Users\\w1nd0ws\\Desktop\\a.txt", "w");
	if (fptr != NULL) {
		printf("Datei wurde erfolgreich erstellt!\n\n");	
	}else {
		printf("Datei konnte nicht erstellt werden.\n");
		return 0;
	}
	printf("beliebig viele Integerzahlen eingeben. [char eingeben für ende]: \n\n");
	printf("1.te Zahl: ");
	while (1) {
		Anzahl++;
		isEndOfInput = scanf_s("%d", &num);		
		if (isEndOfInput != 0) {	
			fprintf(fptr, "%d\n", num);		
			printf("%d.te Zahl: ", Anzahl);
		}
		else {
			break;									//Wenn keine zahl -> break While
		}
	}
	fclose(fptr);									//Datei schließen
	fptr = NULL;									
	return 0;
}

int Ausgabe(FILE *fptr) {
	int num, i = 0;
	float Durchschnitt = 0;
	fopen_s(&fptr, "C:\\Users\\w1nd0ws\\Desktop\\a.txt", "r");
	if (fptr != NULL) {									//Check ob Datei geöffnet wurde
		printf("\nDatei wurde erfolgreich geoeffnet!\n\n");
	}else {
		printf("\nDatei konnte nicht goeffnet werden.\n");
		return 1;
	}
	printf("\nDer Durchschnitt aller eingegebenen Zahlen war folgender:\n");
	while (fscanf_s(fptr, "%d", &num) != EOF) {					//Datei wird ausgelesen und in num gespeichert bis EOF kommt
		Durchschnitt += num;									
		i++;
	}
	Durchschnitt = Durchschnitt / i;
	printf("\n%f\n", Durchschnitt);	
	fclose(fptr);
	return 0;
}


int main(void) {
	FILE *fptr = NULL;
	int isError = 0;
	isError = Eingabe(fptr);
	if (isError) {						//err check
		printf("ein Fehler ist aufgetreten, Programm wird geschlossen.");
		isError = 0;				//err reset
		return -1;
	}
	isError = Ausgabe(fptr);
	if (isError) {	//err check
		printf("ein Fehler ist aufgetreten, Programm wird geschlossen.");
		return -1;
	}
	return 0;
}
