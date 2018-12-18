#include <iostream>
#include <sstream>
#include "Polygonline.hpp"

// Konstruktoren
Polygonline::Polygonline() {
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse PolygonLine, Objekt: " << getId()
			<< std::endl;

	start = nullptr;
	end = nullptr;
}
Polygonline::Polygonline(Point point) {
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse PolygonLine, Objekt: " << getId()
			<< std::endl;

	start = new PlgElement(point);
	end = start;
}

Polygonline::Polygonline(const std::string s) {
	if (debugConstructor)
		std::cout << "Konstruktor der Klasse PolygonLine, Objekt: " << getId()
			<< std::endl;

	size_t pos = 0;
	start = nullptr;
	end = nullptr;
	
	// nix tun, wenn kein Punkt enthalten
	if (s.find("(") == std::string::npos)
		return;

	do {
		addPoint(Point(s.substr(pos++)));
	} 	while ((pos = s.find("-", pos)) != std::string::npos);
}

// Destruktor
Polygonline::~Polygonline() {
	if (debugConstructor)
		std::cout << "Destruktor der Klasse PolygonLine, Objekt: " << getId()
			<< std::endl;

	while (start != nullptr) {
		PlgElement* tmp = start->next;
		delete start;
		start = tmp;
	}
}

Polygonline& Polygonline::addPoint(const Point point) {
	PlgElement* tmp = new PlgElement(point);
	if (start == nullptr) {
		start = tmp;
		end = tmp;
	} else {
		end->next = tmp;
		end = tmp;
	}

	return *this;
}

Polygonline& Polygonline::appendPolygonline(const Polygonline& line) {
	PlgElement* tmp = line.start;
	while (tmp) {
		addPoint(tmp->point);
		tmp = tmp->next;
	}

	return *this;
}

Polygonline& Polygonline::move(int dx, int dy) {
	PlgElement* tmp = start;
	while (tmp) {
		tmp->point.move(dx, dy);
		tmp = tmp->next;
	}

	return *this;
}

Polygonline& Polygonline::print(bool endl /*= true*/) {

    std::cout << toString() << (endl ? "\n" : "");
	return *this;
}

std::string Polygonline::toString() const
{
    std::ostringstream out;
    out << "|";
    PlgElement* tmp = this->start;
    while(tmp)
    {
        out << tmp->point.toString();
        if(tmp->next)
        {
            out << " - ";
        }
        tmp = tmp->next;
    }
    out << "|";
    return out.str();
}

Polygonline& Polygonline::operator+(const Point &p) {
	addPoint(p);
	return *this;
}

Polygonline& Polygonline::operator+(const Polygonline &l) {
	appendPolygonline(l);
	return *this;
}
std::ostream& operator<<(std::ostream& out, const Polygonline& pl)
{
    out << pl.toString();
    return out;
}
