#include "stdafx.h"
#include "stdio.h"

float potenz_iter(float a, float b, int n) {
	float Ergebnis = 1.0;

	for (int i = 1; i <= n; i++) {

		Ergebnis = Ergebnis * (a + b);

	}
	return Ergebnis;
}


float potenz_reku(float a, float b, int n) {
	float Ergebnis = 1.0;

	Ergebnis = Ergebnis * (a + b);

	if (n > 1) {
		Ergebnis = Ergebnis * potenz_reku(a, b, --n);
	}
	return Ergebnis;
}


void eingabe(float * ptr_alpha, float * ptr_beta, int * ptr_hoch) {
	printf("\nGib einen Wert fuer a ein [float]: ");
	scanf_s("%f", ptr_alpha);
	printf("\nGib einen Wert fuer b ein [float]: ");
	scanf_s("%f", ptr_beta);
	printf("\nGib einen positiven Wert fuer n ein [int]: ");
	scanf_s("%d", ptr_hoch);
}


int main(void) {
	float a;
	float b;
	int n;
	eingabe(&a, &b, &n);
	printf("\n\n a %6.2f, b %6.2f, n %d", a, b, n);
	printf("\nErgebnis iterativ: %14.6f\n", potenz_iter(a, b, n));
	printf("\nErgebnis rekursiv: %14.6f\n", potenz_reku(a, b, n));

	getchar();
	getchar();
	return 0;
}
