#include "stdafx.h"
#include <stdio.h> 


void einlesen(int *u, double *v, int *w) { 
	printf("\nGib einen ganzzahligen Wert fuer a ein: ");
	scanf_s("%i", u);
	printf("\nGib einen reellen Wert fuer x ein: ");
	scanf_s("%lf", v);
	printf("\nGib einen ganzzahligen Wert fuer N ein: ");
	scanf_s("%i", w); 
}


double reihe_iter(int a, double x, int n) { 
	double y = 0.0;
	
	for (int i = 1; i <= n; i++) {
		y = y + (a + 2 * i * x);

	}
	return y;
}



double reihe_reku(int a, double x, int n) { 
	double y = 0.0;
	

	y = y + (a + 2 * n * x);
	
	if ( n > 1) {
	
		y = y + reihe_reku(a, x, --n);
	}
	return y;
}


void ausgeben(double z) {
	printf("\nDie Summe der Reihe ist: %lf\n", z);
}


int main(void) {
	int a;
	double x;
	int N;

	einlesen(&a, &x, &N);
	ausgeben(reihe_iter(a, x, N));
	ausgeben(reihe_reku(a, x, N));
	system("pause");
	return 0;
}

