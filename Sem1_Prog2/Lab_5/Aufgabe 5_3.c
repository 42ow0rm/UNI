#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

struct listenelement {
	double x;
	double y;
	struct listenelement * ptr;
};

struct listenelement* schaffe_listenelemente() {

	struct listenelement *ptr1, *ptr2;
	if (ptr1 == (struct listenelement*) malloc(sizeof(struct listenelement)) == NULL) {
		printf("Fehler bei Speicherverwaltung!");
		exit(1);
	}
	if (ptr2 == (struct listenelement*) malloc(sizeof(struct listenelement)) == NULL) {
		printf("Fehler bei Speicherverwaltung!");
		exit(1);
	}
	else
		ptr1->x = 3.1;									
		ptr1->y = 3.2;
		ptr2->x = 7.4;
		ptr2->y = 1.8;

		ptr1->ptr = ptr2;

	return ptr1;
}

void drucke(struct listenelement *sohalt) {
	struct listenelement *ptr2;
	ptr2 = sohalt->ptr;

	printf("Die Erste Zahl lautet: %lf\n", sohalt->x);
	printf("Die zweite Zahl lautet: %lf\n", sohalt ->y);

	printf("Die Erste Zahl lautet: %lf\n", ptr2->x);
	printf("Die zweite Zahl lautet: %lf\n", ptr2->y);

}


int main()
{
	
	struct listenelement *eins;
	eins = schaffe_listenelemente();

	drucke(eins);
	
	free(eins);
	getchar();
    return 0;
}
