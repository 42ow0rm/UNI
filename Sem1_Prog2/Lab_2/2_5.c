#include <stdio.h>

float sum(float f1, float f2){
	return (f1 + f2);
}

float dif(float f1, float f2){
	return (f1 - f2);
}

float mul(float f1, float f2){
	return (f1 * f2);
}

float div(float f1, float f2){
	return (f1 / f2);
}

float mw(float f1, float f2){
	return ((f1 + f2)/ 2);
}

int main(){
	double eingabe_1, eingabe_2;
	int i;
	
	printf ("\nGeben Sie bitte ein Float-Wert ein: ");
	scanf("%lf",&eingabe);
	printf("%.3lf", eingabe);
		
		
	return 0;
}
