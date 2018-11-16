#include <iostream>
#include "MyString.hpp"
#include "Fahrzeug.hpp"

int main(){
	Fahrzeug f1("ES - H 1234");
	cout << f1 <<endl;
	f1.fahren(101.5);
	cout << f1 << endl;
	Fahrzeug f2("ES - M 4711");
	f2.fahren(10.57);
	cout << f2 << endl;
	return 0;
}
