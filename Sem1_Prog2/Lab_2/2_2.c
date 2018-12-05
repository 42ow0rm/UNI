/* Datei ueberlau.c */ 
#include <stdio.h> 
#define ARRY_LEN 4 

int ar0[ARRY_LEN]; 
int ar1[ARRY_LEN]; 
int k; 
int l; 
int p; 
int q; 
 
int main (void) {  
	for (k = 0; k < ARRY_LEN; k++)  {   
		ar0[k] = 123-2*k;   ar1[k] = 5;  
	}  
	k = 55;  
	l = 54;  
	p = 53;  
	q = 52; 
	printf ("ar1[-1] ist %i\n", ar1[-1]);  
	printf ("ar1[-2] ist %i\n", ar1[-2]);  
	printf ("ar1[-3] ist %i\n", ar1[-3]);  
	printf ("ar1[0]  ist %i\n", ar1[0]);  
	printf ("ar1[ARRY_LEN  ] ist %i\n", ar1[ARRY_LEN]);  
	printf ("ar1[ARRY_LEN+1] ist %i\n", ar1[ARRY_LEN+1]);  
	ar1[ARRY_LEN+2] = 201;  
	ar1[ARRY_LEN+3] = 202;  
	printf ("k ist %i\n", k);  
	printf ("l ist %i\n", l);  
	printf ("p ist %i\n", p);  
	printf ("q ist %i\n", q); 

	//Memorymap
	printf("\n Name		Adress			Value");
	printf("\n ar0:		%p", &ar0);	
	printf("\n ar0[0]:	%p	%i", &ar0[0], ar0[0]);	
	printf("\n ar0[1]:	%p	%i", &ar0[1], ar0[1]);	
	printf("\n ar0[2]:	%p	%i", &ar0[2], ar0[2]);	
	printf("\n ar0[3]:	%p	%i", &ar0[3], ar0[3]);	
	
	printf("\n ar1:		%p", &ar1);
	printf("\n ar1[0]:	%p	%i", &ar1[0], ar1[0]);
	printf("\n ar1[1]:	%p	%i", &ar1[1], ar1[1]);
	printf("\n ar1[2]:	%p	%i", &ar1[2], ar1[2]);
	printf("\n ar1[3]:	%p	%i", &ar1[3], ar1[3]);
	
	printf("\n k:		%p	%i", &k, k);
	printf("\n l:		%p	%i", &l, l);
	printf("\n p:		%p	%i", &p, p);
	printf("\n q:		%p	%i", &q, q);
	getch(); //wait...
	
	
	return 0;
 } 

