#include <iostream>
#include "MyData.hpp"
#pragma once

using namespace std;

class MyListElement;

class MyList
{
public: 
	MyList  ();
	MyList	(const MyList &);
	~MyList ();
	
	void         clear(); // Liste wird geleert
	unsigned int size(); // Anzahl der Elemente werden zurück geliefert
	bool		 empty(); // prüft, ob Liste leer ist
	MyData &	 at(unsigned int) const;
	void		 push_back(const MyData &); // Ein Element wird gehängt
	void		 pop_back(); // Element wird gelöscht
	MyData&		 front() const; // erste Element wird zurück geliefert
	MyData&		 back()  const; // letzte Element wird zurück geliefert
	void		 print();
	MyList&		 operator= (const MyList &);
	MyList&		 operator+ (const MyList &);

private:
	MyListElement * first;
	MyListElement * last;
	unsigned int Size;
};

class MyListElement
{
public:
	friend MyList;

	MyListElement(MyData * data) : data(data) {}

	~MyListElement()
	{
		delete data;
		delete next;
	}

private:
	MyListElement * next;
	MyData		  * data;
};
