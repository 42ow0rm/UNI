//v0.1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void PrintChildStart(int id, pid_t _pid){

	switch(id){
		case 0: exit(0);
		case 1: printf("Client xterm mit der PID %d gestartet\n", _pid); break; //execl("/bin/xterm", "xterm");
		case 2: printf("Client xclock mit der PID %d gestartet\n", _pid); break; //execl("/bin/xclock", "xclock"); 
		case 3: printf("Client xload mit der PID %d gestartet\n", _pid); break; //execl("/bin/xload", "xload"); 
	}


}

int MainMenu(int id, int pr_count){	
	char* input;
	printf("Programm zu Start auswaehlen:\n");
	printf("	[1] ... xterm\n");
	printf("	[2] ... xclock\n");
	printf("	[3] ... xload\n");
	if(pr_count > 0){
		printf("	[9] ... Client beenden\n");
	}
	printf("	[0] ... Diese Programm beenden\n");
	printf("Bitte Zahl eingeben: ");
	
	scanf("%c", &input);	
	printf("\n");
	
	printf("%c", input);
	return *input;
}

int main(){
	int id = -1;		//is id Mainmenu
	int pr_count = 0;	//count processes
	pid_t my_pid, parent_pid, child_pid, pid_xterm, pid_xclock, pid_xload;

	for(;;){
		
		if (id != -1){ //start client with pid
	
			// print error message if fork() fails
			if((child_pid = fork()) < 0 )
			{
		        	perror("fork failure");
		        	exit(1);
		     	}
	
			// child prpocess begin here	
			if(child_pid == 0){
				switch(id){
					case 0: exit(0);
					case 1: execl("/bin/xterm", "xterm", NULL); break;
					case 2: execl("/bin/xclock", "xclock", NULL); break; 
					case 3: execl("/bin/xload", "xload", NULL); break; 
				}	
				perror("execl() failure!\n");
				PrintChildStart(id, child_pid);
				exit(0);
			}

			//save the pid of the process
			switch(id){
				case 1: pid_xterm = child_pid; break;
				case 2: pid_xclock = child_pid; break; 
				case 3: pid_xload = child_pid; break; 	
			}
		} // end  of  -- if (id != -1) --


		id = MainMenu(id, pr_count);
		printf("%d \n", id);

		if(id > 0 && id < 9){ //process has started
			pr_count++;			
		}
		if(id == 9){
			printf("%d \n", id);

		}

		printf("\e[1;1H\e[2J"); //clear screen
	} // end of -- for --
	return 0;
}


// kill()
