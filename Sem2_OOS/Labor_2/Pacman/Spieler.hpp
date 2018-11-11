//#pragma once
#include <iostream>
#include "MyString.hpp"
#include "Position.hpp"
#include "Labyrinth.hpp"
//#include "PacMan.hpp" 

using namespace std;

class Spieler {
private:
	MyString name;
	Position pos;
	int muenzen;
public:
	Spieler(MyString name);
	Spieler(char * name);
	Position &getPos();
	void setPos(Position &pos);
	void setRichtung(Richtung &dir);
	int getMuenzen();
	void plusMuenze();
	Spieler & schritt(Labyrinth &lab);
	void orientieren(Labyrinth & lab);

};
