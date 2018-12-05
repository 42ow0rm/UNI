#include <stdio.h>


int main(){
	double eingabe, min;
	int i;
	
	for(i=0; i<4; i++){
		printf ("\nGeben Sie bitte ein Double-Wert ein: ");
		scanf("%lf",&eingabe);
		printf("%.3lf", eingabe);
		//scanf ("%d", &eingabe);
		//printf("%d", eingabe);
		
		
		if(i == 0){	
			min = eingabe;
		}else {
			if(eingabe < min){
				min = eingabe;
			}
		}
	}
	
	printf("\n\n-------------------------------------------\nMin. ist: %.3lf", min);	
	return 0;
}
