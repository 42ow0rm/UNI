#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct element_typ { 
	char name[20];
	int alter; 
				};


struct element_typ *element_erzeugen(void) {
	
	struct element_typ * i;
	i = (struct element_typ*) malloc(sizeof(struct element_typ));
	if (i == NULL) {
		printf("Kein Speicher");
	} 
	return i;
}

void edit_element(struct element_typ * variable) {
	
	strcpy_s(variable->name, 20, "Frank");
	variable->alter = 24;

}

void element_ausgeben(struct element_typ * variable) {
	
	printf("Der Name lautet: %s\n", variable->name);
	printf("Das Alter ist: %i", variable->alter);

}

int main(void) {
	struct element_typ * ptr_objekt;
	ptr_objekt = element_erzeugen();
	edit_element(ptr_objekt);
	element_ausgeben(ptr_objekt);
	free(ptr_objekt);

	getchar();
	return 0;
}

