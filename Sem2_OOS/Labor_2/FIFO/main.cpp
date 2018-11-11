#include <iostream>
#include "Fifo.hpp"

using namespace std;

int main() {
	Fifo fifo(20);
	fifo.push('c');
	fifo.push('d');
	fifo.push('a');
	cout << fifo.pop();
	cout << fifo.pop();
	cout << fifo.pop();
	getchar();
	getchar();
	return 0;
}
