#include "stdafx.h"
#include "stdio.h"


void zeige(void) 
{ 
	int c;
	c = getchar();					//Benutzer gibt Wert ein, welcher in c gespeichert wird
	if (c != '\n') zeige();			//solange c ungleich Enter ist, Selbstaufruf
	putchar(c);						//verdreht die einzelnen Zeichenketten des Wertes c
}

int main(void) 
{
	printf("\n\n\n");
	zeige();					//Methodenaufruf zeige
	system("pause");
	return 0; 
}

