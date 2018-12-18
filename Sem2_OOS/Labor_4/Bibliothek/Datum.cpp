#include "Datum.hpp"

Datum::Datum(int tag, int monat, int jahr) {
	this->tag = tag;
	this->monat = monat;
	this->jahr = jahr;
}

Datum::Datum(const string & datum) : Datum() {
	istringstream is(datum);
	char c;
	is >> tag >> c >> monat >> c >> jahr;
}

Datum::Datum(const char * datum) : Datum() {
	string datum1(datum, 10);
	istringstream is(datum1);
	char c;
	is >> tag >> c >> monat >> c >> jahr;
}

Datum Datum::operator+(int tage) {
	tag += tage;
	while (tag > 30) {
		if (tag > 30) {
			++monat;
			tag -= 30;
		}
		if (monat > 12) {
			++jahr;
			monat -= 12;
		}
	}
	return *this;
};

ostream & operator<<(ostream & os, const Datum & datum) {
	return os << datum.tag << "." << datum.monat << "." << datum.jahr;
};
