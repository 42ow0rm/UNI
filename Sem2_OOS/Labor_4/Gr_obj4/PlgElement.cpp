#include <iostream>
#include "PlgElement.hpp"

PlgElement::PlgElement(Point point) {
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse PlgElement, Objekt: "
			<< this->point.getId() << std::endl;
	this->point.setX(point.getX());
	this->point.setY(point.getY());
	this->next = nullptr;
}

PlgElement::~PlgElement() {
	if (debugConstructor)
		std::cout << "Destruktor der Klasse PlgElement, Objekt: "
			<< this->point.getId() << std::endl;
}
