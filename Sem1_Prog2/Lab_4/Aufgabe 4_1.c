#include "stdafx.h"
#include "stdio.h"

int fakultaet(int);
int eingabe();

int main()
{
	int Zahl, Ergebnis;
	int *ptr;
	ptr	= &Ergebnis;
	Zahl = eingabe();
	printf("Die Fakultaet ist: %i\n", fakultaet(Zahl));
	system("pause");
    return 0;
}

int eingabe(void) {
	int n = 0;

	printf("Herzlich Willkommen. Wollen sie eine Fakultaet berechnen? \nBitte eine ganze Zahl eingeben:");
	scanf_s("%i", &n);
	return n;
}

int fakultaet(int n) {
	int Ergebnis;

	printf("%p\n", &n);


	if (n > 1) {
		

		return n = n * fakultaet(n-1);
			
	}
	else
	{
		return 1;
	}
	
	
}
