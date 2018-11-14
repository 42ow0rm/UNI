#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	char *strPtr;
	unsigned int strSize, strCapacity;

public:
	MyString(void);
	MyString(const char *cStr);
	MyString(const MyString &mStr);
	~MyString();
	void reserve(unsigned int c);
	MyString &append(MyString &str);
	MyString &assign(MyString str);
	const char *c_str(void);
	int size(void);
	int capacity(void);
	void clear(void);
	bool empty(void);
	char &at(int i);
	
	MyString operator= (const MyString& s1);
	friend MyString operator+ (const MyString& s1, const MyString& s2);
	bool operator == (MyString & s);//
	bool operator != (MyString & s);//
	char& operator[](int pos);
	void print(ostream & out);//
	void read(istream & in);//
};

ostream & operator << (ostream & out, MyString & str);

	
