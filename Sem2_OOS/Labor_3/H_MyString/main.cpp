#include <iostream>
#include <string>
#include "MyString.hpp"

using namespace std;

int main(){
	MyString s1("Eins ");
	MyString s2("Zwei ");
	MyString s3("Drei ");
	MyString s4("NIX");
	
	s4 = s1 + s2 + s3;
	s2 = s1;
	s2.assign(s1);
	cout << "sind s1 und s2 gleich? " << boolalpha << (s1==s2) << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
}

