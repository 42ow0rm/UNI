#include <stdio.h> 

int main(void) {
	FILE * fp;
	char puffer[81];
	int  c;
	int i;
	int Zeile = 0;
	fopen_s(&fp, "C:\\Users\\w1nd0ws\\Desktop\\a.txt", "r");
	while (1) {
		Zeile++;			
		if (feof(fp)) {	//check eof erreicht wurde
			break;		
		}
		for (i = 0; (i < 80) && ((c = fgetc(fp)) != EOF) && (c != '\n'); i++) {	
			puffer[i] = c;		
		}
		puffer[i] = '\0';															//add terminator \0
		//printf("\nDie %d.te Zeile der Datei lautet:\n%s\n", Zeile, puffer);	
		printf("\n%s", puffer);
	}
	fclose(fp);	//close file
	return 0;
}
