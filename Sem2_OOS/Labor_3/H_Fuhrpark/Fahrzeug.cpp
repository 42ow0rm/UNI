#include <iostream>
#include "Fahrzeug.hpp"
#include "MyString.hpp"

using namespace std;

int Fahrzeug::count = 0;

Fahrzeug::Fahrzeug(){
	count++;
	this->km = 0;	
	this->vin = count;
}

Fahrzeug::Fahrzeug(const Fahrzeug& f){
	count++;
	this->km = 0;
	this->vin = count;
}

Fahrzeug::Fahrzeug(MyString &kenz){
	count++;
	this->km = 0;	
	this->vin = count;
}

Fahrzeug::Fahrzeug(char *str){
	count++;
	MyString kenz(str);
	kz.assign(kenz);
	this->km = 0;
	//cout << count << endl;
	this->vin = count;
}

Fahrzeug::~Fahrzeug(){
	count--;
}
		
int Fahrzeug::getCount(){
	return count;
}
	
void Fahrzeug::setKenz(MyString &kenz){
	this->kz.assign(kenz);
}

const char* Fahrzeug::getKenz(){
	return this->kz.c_str();
}

void Fahrzeug::fahren(double d){
	this->km += d; 
}

double Fahrzeug::getKm(){
	return this->km;
}

unsigned int Fahrzeug::getVIN(){
	return this->vin;
}

ostream& operator<< (ostream & s, Fahrzeug& f){
	return s << f.getKenz() << " VIN = " << f.getVIN() << " km = " << f.getKm();
}

