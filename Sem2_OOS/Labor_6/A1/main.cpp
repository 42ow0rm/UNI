// main.cpp zur Demonstration der vorhersehbaren Fehler

#include <iostream>
#include "Polygonline.hpp"
using namespace std;

bool debugConstructor = false;

unsigned int ObjectCounter::maxId = 0;
unsigned int ObjectCounter::number = 0;

int main() {
    try {
        // Punkt erstellen und Infos ausgeben
        const Point p;
        cout << "maxId = " << ObjectCounter::getMaxId() << endl;
        cout << "ID von p = " << p.getId() << endl;
        //cout << &ObjectCounter::maxId << endl;
        // ID von p unerlaubt �ndern
        *(((int*)(&p))+2) = ObjectCounter::getMaxId() + 10;
        // Punkt ausgeben
        cout << "ID von p = " << p.getId() << endl;
        try {
            p.print();
        } catch (DrawingObject::IdTooHigh& e) {
            cout << "caught IdTooHigh exception " << e.getId() <<endl;
        }
        // Polygonline erstellen und ausgeben
        Polygonline pl;
        pl.addPoint(Point(1, 1));
        pl.addPoint(Point(2, 2));
        pl.addPoint(Point(3, 3));
        pl.addPoint(Point(4, 4));
        pl.print();
        // Polygonline unerlaubt �ndern
        PlgElement * first = (PlgElement *)(*((int*)(&pl) + 4));
        PlgElement * last = (PlgElement *)(*((int*)(&pl) + 6));
        last->setNext(first);
        // Polygonline ausgeben
        try {
            pl.print();
        } catch (Polygonline::LoopInLine& e) {
            cout << "caught LoopInLine exception " << e.getId() << endl;
        }
    } catch (DrawingObject::GraphException& e) {
        cout << "caught GraphException " << e.getId() << endl;
    }
    return 0;
}
