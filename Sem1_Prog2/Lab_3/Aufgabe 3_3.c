#include "stdafx.h"
#include "stdio.h"
#include <math.h>

#define PI 3.141592

void kugel(double , double *, double *);
void Wuerfel(double , double , double , double *, double *, double *);
void einlesen( double *);

int main()
{
	double Radius, Flaeche, Volumen, laenge, breite, hoehe, Diagonale;
	int check = 0;
	
	printf("Willkommen bei der Berrechnung von Kugeln und Wuerfeln!\n\n");
	printf("Wir beginnen mit der Berrechnung der Kugel:\n\n");
	system("pause");
	printf("\n");
	printf("Geben sie dafuer eine Zahl fuer Radius eingeben [in cm]\n");													//START Kreis																							
	scanf_s("%lf", &Radius);
	kugel(Radius, &Flaeche, &Volumen);
	printf("Die Flaeche betraegt: %.2lf cm^2\nDas Volumen betraegt: %.2lf cm^3\n\n", Flaeche, Volumen);			//END Kreis

	printf("Nun folgt die Berechnung zum Kasten\n\n");												//START Kasten
	printf("Bitte eine laenge eingeben [in cm]\n");
	scanf_s("%lf", &laenge);
	printf("Bitte eine breite eingeben [in cm]\n");
	scanf_s("%lf", &breite);
	printf("Bitte eine hoehe eingeben [in cm]\n");
	scanf_s("%lf", &hoehe);
	Wuerfel(laenge, breite, hoehe, &Flaeche, &Volumen, &Diagonale);
	printf("Die Flaeche betraegt: %.2lf cm^2\nDas Volumen betraegt: %.2lf cm^3\nDie Diagonale betraegt: %.2lf cm\n\n", Flaeche, Volumen, Diagonale);			//END Kasten

	system("pause");
    return 0;
}


void kugel(double R, double *F, double *V) {						//Funktion zur Berechnung von Fläche und Volumen
	double rds = R;
	*F = 4 * PI * rds * rds;
	*V = (4 * PI * rds * rds * rds) / 3;

}

void Wuerfel(double a, double b, double c, double *F, double *V, double *D) {		//Funktion zur Berechnung von
																					//Fläche, Volumen und Diagonale
	*F = 2 *(a * b + a * c + b * c) ;
	*V = a * b * c;
	*D = sqrt(sqrt( a * a + b * b) + c * c );

}
