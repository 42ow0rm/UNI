#include <stdio.h>

int main(){
	int step = 1;
	
	char *abc = "Dies ist ein Array, aber wie groﬂ denn?";
	printf("\nSize of abc[]:		%i\n", sizeof(abc));
	
	for(int i = 0; i < sizeof(abc); i+=step){
		printf("\nSize of abc[%i]:		%i", i, sizeof(abc[i]));
	}
	printf("\n");
	
	//---------------------------------------------------------------
	int* arr[100];
	printf("\nSize of arr[]:		%i\n", sizeof(arr));
	
	step = 100;
	for(int i = 0; i < sizeof(arr); i+=step){
		printf("\nSize of arr[%i]:	%i", i, sizeof(arr[i]));
	}
	printf("\n");
	

	//---------------------------------------------------------------
	double* d_arr[100];
	printf("\nSize of d_arr[]:	%i\n", sizeof(d_arr));
	
	step = 100;
	for(int i = 0; i < sizeof(d_arr); i+=step){
		printf("\nSize of d_arr[%i]:	%i", i, sizeof(d_arr[i]));
	}
	printf("\n");
	
	printf("\n\n---------------------------------------------------------------\n");
	long double size_ld = 3.1456787654322134567890876543245;
	double size_d = 3.1456787654322134567890876543245;
	float size_f = 3.145678765432;
	int size_i = 3;
	printf("\nSize of long double:	%i\n", sizeof(size_ld));
	printf("\nSize of double:		%i\n", sizeof(size_d));
	printf("\nSize of float:		%i\n", sizeof(size_f));
	printf("\nSize of int:		%i\n", sizeof(size_i));
	return 0;
}
