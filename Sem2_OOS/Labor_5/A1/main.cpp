#include <iostream>
#include <string>
using namespace std;

void p(string s, bool nl = true) {
	cout << s << " ";
	if (nl) { cout << endl; }
}

class A {
public:
	void f1() { p("A::f1()"); }
	virtual void f2() { p("A::f2()"); }
	void f3() { p("A::f3()"); }
	void f4() { p("A::f4()", false); f2(); }
};

class B : public A {
public:
	void f1() { p("B::f1()"); }
	virtual void f2() { p("B::f2()"); }
	void f3() { p("B::f3()"); }
	virtual void f4() { p("B::f4()", false); f2(); }
};

class C : public B {
public:
	void f1() { p("C::f1()"); }
	virtual void f2() { p("C::f2()"); }
	virtual void f3() { p("C::f3()"); }
	virtual void f4() { p("C::f4()", false); f2(); }
};

class D : public C {
public:
	void f1() { p("D::f1()"); }
	virtual void f2() { p("D::f2()"); }
	void f3() { p("D::f3()"); }
};

int main() {
	D d;
	A * aptr = &d;
	B * bptr = &d;
	C * cptr = &d;
	aptr->f1();
	bptr->f1();
	cptr->f1();
	
	aptr->f2();
	bptr->f2();
	cptr->f2();
	
	aptr->f3();
	bptr->f3();
	cptr->f3();
	
	aptr->f4();
	bptr->f4();
	cptr->f4();
}

