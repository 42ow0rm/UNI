#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void sigquit(); 
 
void clearScreen(){
	printf("\e[1;1H\e[2J\n");
}

void printArray(int max_length, int arr[]){
	int i = 0;
	for (i; i < max_length; i++){
		printf("%d \n", arr[i]);
	}
}

void defragmentList(int id, int max_length, int arr_proc[], int arr_pids[]){
	int i = id-1;	
	for(i; i < max_length; i++){

		arr_pids[id] = arr_pids[id+1];	//shift +1(up) all elements after the gap 
		arr_proc[id] = arr_proc[id+1];	//shift +1(up) all elements after the gap 

		printArray(max_length, arr_pids);	
	}
	arr_pids[max_length] = 0;
	arr_proc[max_length] = 0;
}

void printProcStart(int id, int pid){
	clearScreen();
	char* client;
	//printf("%d", id);
	switch(id){
		case(1): client = "xterm"; break;
		case(2): client = "xclock"; break;
		case(3): client = "xload"; break;
		default: client = "ERROR!!!!!!!";
	}
	printf("Client %s mit der PID %d gestartet\n\n", client, pid);
}

void printProcList(int max_length, int arr_proc[], int arr_pid[]){
	int i = 0;
	char* client;
	printf("Programm zum beenden auswaehlen:\n");
	for (i; i < max_length; i++){
		if(arr_proc[i] != 0){
			switch(arr_proc[i]){
				case(1): client = "xterm"; break;
				case(2): client = "xclock"; break;
				case(3): client = "xload"; break;
				default: client = "ERROR!!!";
			}
			printf("	[%d] ... %s	-	PID(%d) \n", (i+1), client, arr_pid[i]);
		}
	}
	printf("	---\n	[0] ... Zurueck zum Hauptprogramm\n");	
}

int isChildAlive(int max_length, int arr[]){
	int i = 0;	
	for (i; i < max_length; i++){
		if (arr[i] != 0){
			return 1;
		}
	}
	return 0;
}

void addPid(int pid, int max_length, int arr_pid[]){
	int i = 0;	
	for (i; i < max_length; i++){
		if (arr_pid[i] == 0){
			arr_pid[i] = pid;
			break;
		}
	}
}

int isFull(int max_length, int arr[]){
	int i = 0, res = 1;	
	for (i; i < max_length; i++){
		if (arr[i] == 0 ){
			res = 0;
			break;
		}
	}
	if(res == 1){
		printf("\n\n---------------------------------------\nERR: Process list ist full\n---------------------------------------\n\n");
	}
	return res;
}

void initList(int max_length, int arr[]){
	int i = 0;
	for (i; i < max_length; i++){
		arr[i] = 0;
	}
}

int MenuHandler(int i){
	unsigned int res = 0;
	switch(i){
		case(99): //endlose pause ^^ für gestartete clients
			for(;;)
				;

		case(0): //exit == default
			exit(1);

		case(1): //start xterm
			execl("/usr/bin/xterm", "xterm", NULL);
			MenuHandler(99);

		case(2): //start xclock
			execl("/usr/bin/xclock", "xclock", NULL);
			MenuHandler(99);

		case(3): //satrt xload
			execl("/usr/bin/xload", "xload", NULL);
			MenuHandler(99);

		case(9): //Clients beenden Menu
			do{
				printf("\nBitte Zahl eingeben: ");
				scanf("%u", &res);
				printf("\n");			
			}while(res < 0 || res > 20);
			break;	
	
		case(10): //Main menu **NUR**
			printf("Programm zum Start auswaehlen:\n");
			printf("	[1] ... xterm\n");
			printf("	[2] ... xclock\n");
			printf("	[3] ... xload\n");
			break;

		case(11): //Main menu ohne clients beenden	
			MenuHandler(10);		
			MenuHandler(13);
			res = MenuHandler(14);
			break;

		case(12): //Main menu mit clients beenden
			MenuHandler(10);
			printf("	[9] ... Clients beenden\n");	
			MenuHandler(13);
			res = MenuHandler(14);
			break;
		
		case(13): //Print line Prgm beenden
			printf("	[0] ... Dieses Programm beenden\n");
			break;

		case(14): //Bitte Zahl eingeben
			do{
				printf("\nBitte Zahl eingeben: ");
				scanf("%u", &res);
				printf("\n");			
				//printf("\n%u\n", res);
			}while(res < 0 || res > 9);			
			break;


		default:	
			printf("\n\n---------------------------------------\nERR: ILLEGAL Argument\n---------------------------------------\n\n");
			exit(1);
	}
	return res;
}

int main(){
	clearScreen();
	int max_valid_opt = 3; //anzahl an mögliche prgm zu starten
	unsigned int menu_id = 11; // id=11 -> start with main menu

	int pid;
	int max_length = 12;
	//int c_pids[max_length][1]; //list of all started pids and types of processes
	int c_pids[max_length]; //list of all started pids and types of processes
	int c_proc[max_length]; //list of all started pids and types of processes


	initList(max_length, c_pids); //set list to 0
	initList(max_length, c_proc); //set list to 0

	//printArray(max_length, c_pids);
	//printArray(max_length, c_proc);

	for(;;){ //-----------------------------------------------------------------Main loop
		if (isChildAlive(max_length, c_pids) == 1 && menu_id == 11){//check if any child is alive
			menu_id = 12;
		}

		if ((menu_id > 9 && menu_id != 99) || menu_id == 0){ //-----------------menu-client if			
			menu_id = MenuHandler(menu_id);	
		}else{	// -------------------------------------------------------------start client if (else)
			if (isFull(max_length, c_pids) == 0 || menu_id == 9){ //check queue if is full, or id=9 -> kill proc.
				if(menu_id <= max_valid_opt ) { 	//----------------------------------prevent illegal args
					if ((pid = fork()) == 0) { //-----------------------------------child section				
						MenuHandler(menu_id);
					}else if (pid > 0) {					
						addPid(pid, max_length, c_pids);//add new pid to the list
						addPid(menu_id, max_length, c_proc);//add new proc type to the list
						//printArray(max_length, c_pids);
						//printArray(max_length, c_proc);
						printProcStart(menu_id, pid); // print process started ... pid ...
						menu_id = 11;	//reinitialize menu_id to avoid endless loop

					}//-------------------------------------------------------------end child section
				}else if(menu_id == 9){ //clients beenden
					clearScreen();
					printProcList(max_length, c_proc, c_pids);
					menu_id = MenuHandler(9);
					if (menu_id != 0){ //id = 0 -> return to main menu
						if(c_pids[menu_id-1] != 0){ // check user input to prevent seg. fault
							kill(c_pids[menu_id-1], SIGQUIT); //kill child with sig kill
							c_pids[menu_id-1] = 0;	//free item on the list
							c_proc[menu_id-1] = 0;	//free item on the list
							//defragmentList(menu_id - 1, max_length, c_proc, c_pids); //kick all 0 (gaps) in the list
					
							printArray(max_length, c_pids);
							//printArray(max_length, c_proc);
						}
						menu_id = 9;	//set menu_id to 9 (clients beenden)
					} else {
						menu_id = 11;	//user will zuruck zu hauptmenu
					}
				}else{ 	//----------------------------------------------------------for illegal input exit
					MenuHandler(menu_id);
				}//-----------------------------------------------------------------end illegal input if
			}else{ //if queue is full
				clearScreen();
				menu_id = 11; //nichts tun, zuruck auf hauptmenu
		}
		}//---------------------------------------------------------------------end menu-client if
		


		//printf("\n%u\n", menu_id);
		//sleep(2);
	} //---------------------------------------------------------------------------End main loop
	
	return 0;
}

void sigquit(){ 
	printf("Child process killed!!!\n"); 
	exit(0); 
} 
