#include <stdio.h>
#include "header.h"

#define SPITZE 			1 
#define GUT             2 
#define BEFRIEDIGEND    3 
#define AUSREICHEND     4 
#define DURCHGEFALLEN   5 
#define JA              1 
#define NEIN            0 

void vorgegeben(){
	unsigned int note, bestanden; 
    printf ("\nGeben Sie bitte eine Note (1-5) ein: ");
	scanf ("%u", &note);
	if (note == SPITZE)
		bestanden = JA;
	else if (note == GUT)
		bestanden = JA;
	else if (note == BEFRIEDIGEND)
		bestanden = JA;
	else if (note == AUSREICHEND)
		bestanden = JA;
	else
		bestanden = NEIN;
	bestanden ? printf ("\nOK!,") : printf( "\nNICHT bestanden"); 
    	
}

void switch_case_a(){
	printf("\nteil a \n");
	unsigned int note, bestanden; 
    printf ("\nGeben Sie bitte eine Note (1-5) ein: ");
	scanf ("%u", &note);
	
	//printf("%d", note);
	
	switch(note){
		case SPITZE:		
		case GUT:			
		case BEFRIEDIGEND:	
		case AUSREICHEND:	bestanden = JA; break;
		default:			bestanden = NEIN; break;
	}
	bestanden ? printf ("\nOK!,") : printf( "\nNICHT bestanden"); 	
}

void switch_case_b(){
	printf("\nteil b\n");
	unsigned int note, bestanden;     
	do{
		printf ("\nGeben Sie bitte eine Note (1-5) ein: ");
		scanf ("%u", &note);
		//printf("%u", note);
	}while (note < 1 || note > 5);
	
	switch(note){
		case SPITZE:		
		case GUT:			
		case BEFRIEDIGEND:	
		case AUSREICHEND:	bestanden = JA; break;
		default:			bestanden = NEIN; break;
	}
	bestanden ? printf ("\nOK!,") : printf( "\nNICHT bestanden"); 	
}

int main (void) {    
	//vorgegeben();
	
	//aufgabe a
	switch_case_a();
	
	//aufgabe b
	switch_case_b();
	return 0; 
} 
 
