#include <stdio.h>

void PrintClientStart(int id){
	switch(id){
		case 0: exit(0);
		case 1: printf("Client xterm mit der PID #### gestartet\n"); break; //execl("/bin/xterm", "xterm");
		case 2: printf("Client xclock mit der PID #### gestartet\n"); break; //execl("/bin/xclock", "xclock"); 
		case 3: printf("Client xload mit der PID #### gestartet\n"); break; //execl("/bin/xload", "xload"); 
	}
}

int MainMenu(int id, int pr_count){
	if (id != -1){
		PrintClientStart(id);
	}
	printf("Programm zu Start auswaehlen:\n");
	printf("	[1] ... xterm\n");
	printf("	[2] ... xclock\n");
	printf("	[3] ... xload\n");
	if(pr_count > 0){
		printf("	[9] ... Client beenden\n");
	}
	printf("	[0] ... Diese Programm beenden\n");
	printf("Bitte Zahl eingben: ");
	
	int* input;
	scanf("%d", &input);	
	printf("\n");
	
	return input;
}

int main(){
	int a = -1;
	int pr_count = 0;
	for(;;){
		a = MainMenu(a, pr_count);
		printf("%d \n", a);
	}
}
