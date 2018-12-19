#include "MyList.hpp"
#define _CRT_SECURE_NO_WARNINGS 

MyList::MyList() : first(nullptr), last(nullptr), Size(0)
{
};

MyList::MyList(const MyList &a)					
{
	//Alle pointer auf nullptr setzen sonst zeigen sie irgendwohin 
	first = nullptr;
	last = nullptr;
	Size = 0;
	operator+(a);// Alle Punkte anhängen
	//*this + a;
};

MyList::~MyList()										
{
	clear();	
};

unsigned int MyList::size()
{
	return Size;
};

void MyList::clear()
{
	//delete first;
	first = nullptr;
	last = nullptr;
	Size = 0; 
};

bool MyList::empty()
{
	return Size == 0; 
};


void MyList::push_back(const MyData &d)
{
	MyListElement * el = new MyListElement(d.clone());

	if (first == nullptr)
	{
		first = el;
	}
	else
	{
		last->next = el;
	}
	last = el;
	Size++;
};

void MyList::print()
{
	MyListElement * el = first;
	cout << "\nMyList:\n" << endl;
	for(unsigned int i = 0; i < Size; i++)
	{
		el->data->print();
		el = el->next;
	}
	
	cout << endl;
};

void MyList::pop_back()
{
	delete last;
	Size--;
}

MyData& MyList::front() const
{
	return *first->data;
};

MyData& MyList::back() const
{
	return *last->data;
};

MyList& MyList::operator= (const MyList &a)
{
	return *this;
};
MyList& MyList::operator+ (const MyList &a)
{
	MyListElement * el = a.first;
	for (unsigned int i = 0; i < a.Size; i++) 
	{
		this->push_back(*el->data);
		el = el->next;
	}
	return *this;
};
