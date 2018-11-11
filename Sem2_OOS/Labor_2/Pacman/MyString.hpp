#pragma once

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
};
