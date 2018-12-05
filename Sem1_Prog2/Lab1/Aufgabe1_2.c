#include "header.h"
#include <stdio.h>

int main(){
	int celsius, i;
	
	//Aufgabe 1.2.1
	printf("Aufgabe 1.2.1 for()\n");
	printf("Fahrenheit	Celsius\n");
	for(i = -20; i < 301; i+=20){
		celsius = (5 *(i - 32))/ 9;
		printf("   %d	  	%d\n", i, celsius);
	}
	printf("\n");
	
	//Aufgabe 1.2.2
	printf("Aufgabe 1.2.2 while()\n");
	i = -20;
	printf("Fahrenheit	Celsius\n");
	while(i < 301){
		celsius = (5 *(i - 32))/ 9;
		printf("   %d	  	%d\n", i, celsius);
		i+=20;
	}
	printf("\n");
	
	
	//Aufgabe 1.2.3 teil1
	printf("Aufgabe 1.2.3 (a) (ohne (float))!\n");
	float f_celsius;
	printf("Fahrenheit	Celsius\n");
	for(i = -20; i < 301; i+=20){
		f_celsius = (5 *(i - 32))/ 9;
		printf("   %d	  	%.1f\n", i, f_celsius);
	}
	printf("\n");
	
		//Aufgabe 1.2.3 teil1
	printf("Aufgabe 1.2.3 (a) (mit (float))!\n");
	printf("Fahrenheit	Celsius\n");
	for(i = -20; i < 301; i+=20){
		f_celsius = (float)(5 *(i - 32))/ 9;
		printf("   %d	  	%.1f\n", i, f_celsius);
	}
	printf("\n");
	
	//Aufgabe 1.2.3 b)
	float f_i;
	printf("Aufgabe 1.2.3 (b)\n");
	printf("Fahrenheit	Celsius\n");
	for(f_i = -20; f_i < 301; f_i+=10){
		f_celsius = (5 *(f_i - 32))/ 9;
		printf("   %.2f	%.1f\n", f_i, f_celsius);
	}
	printf("\n");
	
	return 0;
}
