#include "stdafx.h"
#include "stdio.h"


struct messdaten { 
	char *  messgeraetename;
	double  messwert;
	struct messdaten * ptr; 
							};

void ausgabe(struct messdaten *);

int main(void) {
	struct messdaten telegramm1, telegramm2, telegramm3;
	struct messdaten * ptr1, *ptr2, *ptr3;

	ptr1 = &telegramm1;
	ptr2 = &telegramm2;
	ptr3 = &telegramm3;

	/********** Telegramme initialisieren ************/

	/* Messgeraetenamen initialisieren */    
	telegramm1.messgeraetename = "Sensor1";
	telegramm2.messgeraetename = "Sensor2";
	telegramm3.messgeraetename = "Sensor3";

	/* Messwerte initialisieren */    
	telegramm1.messwert = 11.0;
	telegramm2.messwert = 22.0;
	telegramm3.messwert = 33.0;

	/* Pointer initialisieren:
	damit Verkettung des Ringpuffers erzeugen */
	telegramm1.ptr = &telegramm2;         /* zeigt auf Telegramm 2 */
	telegramm2.ptr = &telegramm3;         /* zeigt auf Telegramm 3 */
	telegramm3.ptr = &telegramm1;         /* zeigt auf Telegramm 1 */

	ausgabe(ptr1);		/*  Ausgabe */
							//		ausgabe(ptr2);	
							//	  ausgabe(ptr3);
	
	
	getchar();
	return 0;
}
void ausgabe(struct messdaten *pointer1) {
	struct messdaten * ptr2, *ptr3;

	
	printf("%s:\t", pointer1->messgeraetename);
	
	printf("%.2lf\n", pointer1->messwert);
	
	ptr2 = pointer1->ptr;   /* Pointer2 berechnen */
	
	printf("%s:\t", ptr2->messgeraetename);
	
	printf("%.2lf\n", ptr2->messwert);

	ptr3 = ptr2->ptr;      /* Pointer 3 berechnen */
							
	printf("%s:\t", ptr3->messgeraetename);
	
	printf("%.2lf\n", ptr3->messwert);

}


