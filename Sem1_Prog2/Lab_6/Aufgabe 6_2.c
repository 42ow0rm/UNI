#include "stdafx.h"
#include <stdio.h> 


int main(void) {
	FILE * fp;
	char puffer[81];
	int  c;
	int i;
	int Zeile = 0;

	fopen_s(&fp, "C:\\Users\\Hendr\\Desktop\\Blatt 6\\ZAHLEN.txt", "r");					//Datei wird geöffnet und gelesen


	while (1) {
		Zeile++;																	//Anzahl der Zeilen in der Datei werden gezäht
		if (feof(fp)) {																//überprüfe ob Ende der Datei erreicht wurde 
			break;																	//Wenn ja brich While ab
		}
		for (i = 0; (i < 80) && ((c = fgetc(fp)) != EOF) && (c != '\n'); i++) {		//wenn mehr als 80 wdhs oder wenn Datei zu ende ist 
																					//oder wenn Zeichen ein Zeilenumbruch ist, dann Abbruch
			puffer[i] = c;															//Übergabe des Zeichens an das char array
											
																				
		}
		puffer[i] = '\0';															//Satz endet mit \0
		printf("\nDie %d.te Zeile der Datei lautet:\n%s\n", Zeile, puffer);					//Konsolenausgabe
	}
	
	
	fclose(fp);																		//Datei schließen
	
	system("pause");

	return 0;
}
