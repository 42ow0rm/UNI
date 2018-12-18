#include <iostream>
#include "ObjectCounter.hpp"

extern bool debugConstructor;

ObjectCounter::ObjectCounter(): id(++maxId) {
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse ObjectCounter, Objekt: " << getId()
			<< std::endl;
	number++;	
}

ObjectCounter::~ObjectCounter() {
	if (debugConstructor)
		std::cout << "Destruktor der Klasse ObjectCounter, Objekt: " << getId()
			<< std::endl;
		number--;
}

int ObjectCounter::getId() const {
	return id;
}

int ObjectCounter::getMaxId() {
	return maxId;
}

int ObjectCounter::getNumber() {
	return number;
}

