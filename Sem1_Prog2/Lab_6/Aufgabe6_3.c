#include <stdio.h> 

int put(void) {
	FILE * fp;
	char * string = "Zeichenkette, die in die Datei geschrieben wird\n";
	fopen_s(&fp, "C:\\Users\\w1nd0ws\\Desktop\\a.txt", "a");

	if (!fp) {
		fprintf(stderr, "Kann die Datei nicht oeffnen \n");
		return -1;
	}
	else {
		fputs(string, fp);	
		fclose(fp);								
	}
	return 0;
}

int get(void) {
	FILE *fp;
	char buffer[81];
	int Zeile = 0;
	fopen_s(&fp, "C:\\Users\\w1nd0ws\\Desktop\\a.txt", "r");

	if (!fp) {
		fprintf(stderr, "\n Kann Datei nicht oeffnen\n");
		return -1;
	}
	printf("Die Startadresse lautet: \t\t%p\n\n", buffer);

	while (1) {
		Zeile++;							//Zeilen zaehlen
		if (feof(fp)) {					//check ob eof erreivht ist
			break;
		}
		if (fgets(buffer, 81, fp) != NULL) {
			puts(buffer);	
			//printf("Die %d.te Zeile der Datei lautet: %p\n", Zeile, buffer);			
		}
	}
	fclose(fp);
	return 0;
}

int main(void) {
	put();
	get();
	return 0;
}
