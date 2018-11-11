#include <iostream>
#include "Fifo.hpp"
 
using namespace std;

Fifo::Fifo(int Groesse = 20) {
	this->maxSize= Groesse;
	this->number = 0;
	this->wPos = 0;
	this->rPos = 0;
	this->ptr = new char [Groesse];
}

Fifo::~Fifo() {
	delete [] ptr;
}

int Fifo::getWPos() {
	return this->wPos;
}

int Fifo::getRPos() {
	return this->rPos;
}

bool Fifo::isEmpty() {
	if (number == 0) {
		return true;
	}
	else return false;
}

bool Fifo::isFull() {
	if (number < 19) {
		return false;
	}
	else 
		return true;
}

int Fifo::push(char c) {
		if (!isFull()) {
			ptr[wPos] = c;
			wPos++;
			if (wPos >= maxSize) {
				wPos = 0;
			}
			number++;
			return 0;
		}
		else 
			return -1;
	}


char Fifo::pop() {
	if (!isEmpty()) {
		char value = ptr[rPos];
		this->rPos = rPos + 1;
		this->number = number - 1;

		if (rPos >= maxSize) {
			rPos = 0;
		}
		return value;
	}
	else
		return NULL;
}
