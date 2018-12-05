#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


void pointer_auf_record(void);
struct struktur { 
	int recordnummer;										//Struktur größe 14 Byte
	char inhalt[10]; 
						};

int main(void) {
	printf("\nHier ist main:");						//Konsolenausgabe
	pointer_auf_record();							//Funktionsaufruf

	getchar();
	return 0;
}

void pointer_auf_record(void) {
	struct struktur * ptr;												//Pointer vom typ structure
	ptr = malloc(sizeof(struct struktur));								//ptr zeigt auf, vom Heap reservierten Speicherplaz der größe struktur
	ptr->recordnummer = 3;												//Wertzuweisung auf Datentupel 'recordnummer' von structure struktur
	strcpy_s(ptr->inhalt, "hallo");										//Zeichenkettenzuweisung auf Datentupel 'Inhalt' von Structure Struktur
	printf("\nDie Recordnummer ist %d", (*ptr).recordnummer);			//Konsolenausgabe von Inhalt von recordnummer
	printf("\nDer Inhalt ist %s\n", ptr->inhalt);						//Konsolenausgabe von Inhalt von Inhalt
	free(ptr);															//Befreit den Speicher, welches malloc reserviert hat
}





