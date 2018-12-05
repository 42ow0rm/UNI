#include <stdio.h>

int main (){
	int i;
	int* ptr;
	int** ptrptr;
	
	ptr = &i;
	ptrptr = &ptr;
	
	i = 1;
	
	printf("\ni =		%i", i);
	printf("\nptr =		%i", *ptr);
	printf("\nptrptr =	%i", **ptrptr);
	
	
	printf("\n\n\n");
	**ptrptr = 2;
	
	printf("\ni =		%i", i);
	printf("\nptr =		%i", *ptr);
	printf("\nptrptr =	%i", **ptrptr);
	
	return 0;
}
