#include <iostream>
#include "MyString.hpp"

using namespace std;

int main(){
	MyString cs("Ein konstanter String");
	MyString s(cs);
	s.assign(cs);
	s.append(cs);
	cout << cs.c_str() << endl;
	cout << cs.size() << endl;
	cout << cs.capacity() << endl;
	cout << boolalpha << cs.empty() << endl;
	s = cs + cs;
	cout << (cs==cs) << endl;
	s = cs;
	cout << cs << endl;
	s.at(1) = 'X';
	s[2] = 'Y';
	cout << s << endl;

	return 0;
}

