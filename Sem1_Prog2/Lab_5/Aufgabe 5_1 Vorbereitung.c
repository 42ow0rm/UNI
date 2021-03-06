#include "stdafx.h"
#include <stdio.h> 


struct adresse {
	char strasse[30];								//Datentupel 1
	char ort[30];									// 2
	unsigned int plz;								// 3
	unsigned long telefon_nummer;					// 4
};

struct person { 
	unsigned long personalnummer;
	char nachname[20];
	char vorname[20];
	struct adresse adr;								// Datentupel von struct adresse
	double gehalt;									//5
};




int main(void) {
	struct person gross =
	{    123,
		"Gross",									
		"Max",
	{   "Muehlenweg 1",								//adresse.straße
		"Esslingen",								//adresse.Ort
		73732,										//adresse.plz
		260633L										//telefonnummer
	},
		10000.00									//Gehalt
	};
	struct adresse * ptr2;
	ptr2 = &gross.adr;							//Pointer zeigt auf Datentupel 'Adresse' von der Person 'Gross'
	printf("\nDaten von Herrn Gross:");
	printf("\nPersonalnummer: %d", gross.personalnummer);
	printf("\nNachname: %s", gross.nachname);
	printf("\nVorname:  %s", gross.vorname);
	printf("\nStrasse:  %s", ptr2->strasse);
	printf("\nOrt:      %s", ptr2->ort);
	printf("\nPLZ:      %d", ptr2->plz);
	printf("\nTelefon:  %d", ptr2->telefon_nummer);
	printf("\nGehalt: %.2lf Euro", gross.gehalt);

	getchar();
	return 0;
}


