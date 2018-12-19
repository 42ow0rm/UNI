#include <iostream>
#include "circle.hpp"
#include "Polygonline.hpp"
using namespace std;

// Hauptprogramm
int main_strings(void) {
  string str1 ("(1.1,2.1)");
  string str2 ("<(5.5, 6.6), 10.1>");
  string str3 ("|(1.1,1.2) - (2.1, 2.2) -(3.1,3.2) |");
  Point p (str1);
  Circle c (str2);
  Polygonline l (str3);
  
  cout << p.toString() << endl;
  cout << c.toString() << endl;
  c.move(1.0,2.0);
  cout << c.toString() << endl;
  cout << l.toString() << endl;
  return 0;
}

