#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14;

double grad_to_rad(double winkel){
	
	double rad_winkel = (winkel * 2 * PI / 360); 
	
	return rad_winkel;
}

double trapezFlaeche(double a = -1, double b = -1, double winkel = -1, double c = -1){
	
	if ((a != -1) && (b != -1) && (c == -1) && (winkel != -1)){
		//Fall Paralellogramm
		c = a;
	} else if ((a != -1) && (b != -1) && (c == -1) && (winkel == -1)){
		//Fall Rechteck
		c = a;
		winkel = 90;
	} else if ((a != -1) && (b == -1) && (c == -1) && (winkel == -1)){
		//Fall Quadrat 
		c = a; 
		b = a; 
		winkel = 90; 	
	}
	winkel = grad_to_rad(winkel);
	return (.5 * (a + c) * b * sin(winkel));
}

void aufgabe_a(){
	double a = 2;
	double b = 4;
	double winkel = 45;
	double c = 3.5;	
	cout << trapezFlaeche(a, b, winkel, c) << endl;
}

void aufgabe_b(){
	double a = 3;
	double b = 4;
	double winkel = 45;	
	cout << trapezFlaeche(a, b, winkel) << endl;	
}

void aufgabe_c(){
	double a = 4;
	double b = 5;
	cout << trapezFlaeche(a, b) << endl;		
}

void aufgabe_d(){
	double a = 2;
	cout << trapezFlaeche(a) << endl;	
}

int main(){
	aufgabe_a();
	aufgabe_b();
	aufgabe_c();
	aufgabe_d();
}
