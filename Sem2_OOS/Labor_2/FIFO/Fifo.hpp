#pragma once
#include <iostream>

using namespace std;

class Fifo {
private:
	int maxSize;
	int number;
	char *ptr;
	int wPos;
	int rPos;
public:
	Fifo(int Groesse);
	~Fifo();
	int getWPos();
	int getRPos();
	bool isEmpty();
	bool isFull();
	int push(char);
	char pop();
};