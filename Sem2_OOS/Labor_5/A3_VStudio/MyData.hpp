#include <iostream>
#pragma once

using namespace std;

class MyData
{
public:
	MyData() {};
	virtual ~MyData() {}

	virtual MyData * clone() const = 0;
	virtual void print(bool = true) const = 0;

	virtual MyData & operator=(const MyData &) {
		return *this;
	}
};

