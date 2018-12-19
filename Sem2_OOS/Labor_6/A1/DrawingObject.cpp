#include "DrawingObject.hpp"
#include <iostream>

DrawingObject::DrawingObject() {
	if (debugConstructor) 
		std::cout << "Konstruktor der Klasse DrawingObject, Objekt: " << getId()
			<< std::endl;
}

DrawingObject::~DrawingObject() {
	if (debugConstructor)
		std::cout << "Destruktor der Klasse DrawingObject, Objekt: " << getId() 
			<< std::endl;
}

DrawingObject::GraphException::GraphException(int id): id(id) {
}

int DrawingObject::GraphException::getId() const{
    return this->id;
}

DrawingObject::IdTooHigh::IdTooHigh(int id): GraphException(id) {
}


void DrawingObject::check() const{
    if(this->getId() > this->getMaxId())
    {
        throw IdTooHigh(this->getId());
    }

}
