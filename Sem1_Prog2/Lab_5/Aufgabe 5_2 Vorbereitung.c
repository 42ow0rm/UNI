#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void pointer_auf_int(void);

int main(void) { 
	printf("\nhier ist main");				//Konsolenausgabe
	pointer_auf_int();						//Funktionsaufruf ohne argumente und Rückgabewert

	getchar();
	return 0; 
}

void pointer_auf_int(void) {
	int * ptr;
	ptr = malloc(sizeof(int));										//Speicher der größe Int wird im Heap reserviert
	*ptr = 3;														//der Wert 3 wird in *ptr zugewiesen
	printf("\nDer Wert des Objektes *ptr ist %d", (*ptr));			//Konsolenausgabe, Wert des Pointers *ptr
	free(ptr); 
}



