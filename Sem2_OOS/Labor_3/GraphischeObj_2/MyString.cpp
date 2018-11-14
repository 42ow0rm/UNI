#include "MyString.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" // For ops on char*
#include <iostream>
using namespace std;

char eos = '\0';

int cStrGetLen(char * str) {
	if (str == nullptr)
		return 0;

	int n = 0;
	char * buf = str;
	while (*buf != '\0') {
		n++;
		buf++;
	}
	return n;
}

void cStrCopy(char * ziel, char * quelle, int n) {
	for (int i = 0; i < n; i++)
		ziel[i] = quelle[i];
}

// Konstruktor für leeren String
MyString::MyString(void) {
	this->strSize = 0;
	this->strCapacity = 0;
	this->strPtr = new char;
	this->strPtr[0] = '\0';
}

// Konstruktor der einen CString umwandelt
MyString::MyString(const char *cStr) {
	int i = cStrGetLen((char *)cStr);

	this->strPtr = new char[i + 1];
	this->strSize = i;
	this->strCapacity = 0;

	cStrCopy(this->strPtr, (char *)cStr, i + 1);
}

// Kopierkonstruktor
MyString::MyString(const MyString &mStr) {
	this->strSize = mStr.strSize;
	this->strCapacity = mStr.strCapacity;
	this->strPtr = new char[this->strSize + this->strCapacity + 1];

	cStrCopy(this->strPtr, mStr.strPtr, this->strSize + 1);
}

// Destruktor
MyString::~MyString() {
	delete[] this->strPtr;
}

// Speicherplatz vergrößern
void MyString::reserve(unsigned int c) {
	if (c > (this->strCapacity)) {
		char *buffer = new char[this->strSize + 1];
		cStrCopy(buffer, this->strPtr, this->strSize + 1);

		delete[] this->strPtr;
		this->strPtr = new char[this->strSize + 1 + c];

		cStrCopy(this->strPtr, buffer, this->strSize + 1);

		delete[] buffer;

		this->strCapacity = c;
	}
}

// String anhängen
MyString &MyString::append(MyString &str) {
	this->reserve(str.strSize);

	cStrCopy(this->strPtr + this->strSize, str.strPtr, str.strSize + 1);

	this->strSize += str.strSize;
	this->strCapacity -= str.strSize;

	return *this;
}

// String ersetzen
MyString &MyString::assign(MyString str) {
	this->reserve(str.strSize - this->strSize);

	int totalLengt = this->strSize + this->strCapacity + 1;

	cStrCopy(this->strPtr, str.strPtr, str.strSize + 1);

	this->strSize = str.strSize;
	this->strCapacity = totalLengt - this->strSize - 1;

	return *this;
}

// String als CString zurück geben
const char *MyString::c_str(void) {
	return this->strPtr;
}

//Größe des Strings zurück geben
int MyString::size(void) {
	return this->strSize;
}

// Anzahl der noch freien Zeichen zurück geben
int MyString::capacity(void) {
	return this->strCapacity;
}

// String leeren
void MyString::clear(void) {
	this->strPtr[0] = '\0';
	this->strCapacity = this->strSize;
	this->strSize = 0;
}

// Prüfen ob String leer ist
bool MyString::empty(void) {
	if (this->strPtr[0] == '\0')
		return true;
	else
		return false;
}

// Auf ein einzelnes Zeichen des Strings verweisen
char &MyString::at(int i) {
	if (i <= 0 || i > this->strSize)
		return this->strPtr[this->strSize + this->strCapacity];
	else return this->strPtr[i];
}

MyString MyString::operator= (const MyString& str){
	this->reserve(str.strSize - this->strSize);

	int totalLengt = this->strSize + this->strCapacity + 1;

	cStrCopy(this->strPtr, str.strPtr, str.strSize + 1);

	this->strSize = str.strSize;
	this->strCapacity = totalLengt - this->strSize - 1;
	return *this;
}

MyString operator+ (const MyString& s1, const MyString& s2){
	MyString res;
	
	res.strSize = s1.strSize + s2.strSize;
	res.strPtr = new char[res.strSize + 1];
	
	cStrCopy(res.strPtr, s1.strPtr, s1.strSize);
	cStrCopy(res.strPtr + s1.strSize, s2.strPtr, s2.strSize);
	
	return res;
	
}

bool MyString::operator== (MyString & s){
	//cout << this->strSize << " - " << s.strSize << endl;
	return (strcmp(this->c_str(), s.c_str()) == 0);
}

bool MyString::operator!= (MyString & s){
	return strcmp(this->strPtr, s.strPtr);
}

char& MyString::operator[](int pos){
	if (pos >= this->strSize){
		cout << "Invalid Position B1athch!"	;
	}
	return strPtr[pos];
}

ostream& operator<< (ostream & s, MyString& s1){
	return s << s1.c_str();
}

