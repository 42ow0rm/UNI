#include <stdio.h>
#include "stdafx.h"

int schreib(void) {
	int buffer1[] = { 0,1,2,3,4,5,6,7 };
	double buffer2[] = { 0.5 , 1.5 , 2.5 , 3.5 };							//Double array mit 4 Werten
	FILE * fp;
	size_t ergeb;

	fopen_s(&fp, "C:\\Users\\Hendr\\source\\repos\\Blatt 6.txt", "wb");		//Datei öffnen mit Modus schreiben

	if (!fp) {															//überprüfen ob öffnen geklappt hat
	printf("\nKann Datei nicht oeffnen");
	}
	else {
		
		ergeb = fwrite(buffer1, sizeof(int), 8, fp);				//Inhalt des buffer1 wird in Datei geschrieben und Anzahl in ergeb gegeben
		fclose(fp);
		printf("\n%i intzahlen wurden in die Datei geschrieben\n", ergeb);		//Konsolenausgabe der anzahl IntZahlen
		

		fopen_s(&fp, "C:\\Users\\Hendr\\source\\repos\\Blatt 6.txt", "wb");		//Datei öffnen mit Modus schreiben

		if (!fp) {
			printf("\nKann Datei nicht oeffnen");
		}
		else {
			
			ergeb = fwrite(buffer2, sizeof(double), 4, fp);
			fclose(fp);
			printf("\n%i Doublezahlen wurden in die Datei geschrieben\n", ergeb);		//Konsolenausgabe der anzahl IntZahlen
			
		}
	}

	return 0;
}


int lies(void) {
	int buffer1[10];
	double buffer2[5];
	FILE * fp;
	int ergeb;
	int LV = 0;

	fopen_s(&fp, "C:\\Users\\Hendr\\source\\repos\\Blatt 6.txt", "rb");			//Datei öffnen mit Modus lesen
	if (!fp) {
		printf("\nKann Datei nicht oeffnen");
	}
	else {
		ergeb = (int)fread(buffer1, sizeof(int), 8, fp);		//Datei nach Intzahlen auslesen und in buffer1 speichern 
		printf("\n");
		for (LV = 0; LV < ergeb; LV++) {							//Ausgabe der Intzahlen
			printf("\nin buffer[%i] wurde aus der Datei ", LV);
			printf("Blatt 6 folgende Zahl eingelesen: %i", buffer1[LV]);		
		}
		if (feof(fp)) {
			printf("\nDateiende erreicht");
			fclose(fp);
			printf("\n");
			printf("\ninsgesamt %i Zahlen aus der Datei gelesen", ergeb);
		}

		fopen_s(&fp, "C:\\Users\\Hendr\\source\\repos\\Blatt 6.txt", "rb");
		if (!fp)
		{
			printf("\nKann Datei nicht oeffnen");
		}
		else {
			ergeb = (int)fread(buffer2, sizeof(double), 4, fp);			//Datei nach Doublezahlen auslesen und in buffer2 speichern 
			printf("\n");

			for (LV = 0; LV < ergeb; LV++) {
				printf("\nin buffer[%i] wurde aus der Datei ", LV);									//Ausgabe des iten Buffer
				printf("Blatt 6 hat die folgende Zahl eingelesen: %.1lf", buffer2[LV]);				//Ausgabe des Inhalts des ien Double arrays
			
			}
			if (feof(fp)) printf("\nDateiende erreicht");
			fclose(fp);
			printf("\n");
			printf("\ninsgesamt %i Zahlen aus der Datei gelesen", ergeb);
		}
	}

	return 0;
}

int main(void) {

	schreib();
	lies();
	getchar();
	return 0;
}
