#include "stdafx.h"
#include <stdio.h> 


struct adresse {
	char strasse[30];
	char ort[30];
	unsigned int plz;
	unsigned long telefon_nummer; 
};

struct person { 
	unsigned long personalnummer;
	char nachname[20];
	char vorname[20];
	struct adresse adr;
	double gehalt;
};

void drucke_ang(struct person * ptr) {

	
	printf("\nDaten von Herrn Gross:");
	printf("\nPersonalnummer: %d", ptr->personalnummer);
	printf("\nNachname: %s", ptr->nachname);
	printf("\nVorname:  %s", ptr->vorname);
	printf("\nStrasse:  %s", ptr->adr.strasse);
	printf("\nOrt:      %s", ptr->adr.ort);
	printf("\nPLZ:      %d", ptr->adr.plz);
	printf("\nTelefon:  %d", ptr->adr.telefon_nummer);
	printf("\nGehalt: %.2lf Euro", ptr->gehalt);

}


int main(void) {
	struct person gross =
	{    123,
		"Gross",									//Datentupel 1
		"Max",
	{   "Muehlenweg 1",								//Datentupel 2
		"Esslingen",
		73732,
		260633L
	},
		10000.00									//Datentupel 3
	};
	
	struct person * ptr2;
	ptr2 = &gross;					//Pointer zeigt auf Struktur Person 'Gross'
	drucke_ang(ptr2);
	getchar();
	return 0;
}


