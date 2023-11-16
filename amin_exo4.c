#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

/*
	my version of doing it :  1 for tree , 2 for last "  



*/

	void arbre (int n){
	
	int i;
	printf("launching a tree process from  %d \n",getpid());

	for( i=0 ;i< n;i++){

		
		if(fork()==0){
		printf("- process %d from parent %d-\n" , getpid(),getppid());
		exit(0); 
		}
	}

//	for( i=0;i<n;i++){wait(NULL);   }


	
	}
	void chaine(int n ){
	
	int i ; 
	printf("launching a list process from %d \n",getpid());
	
	int  x =fork();

	for(i = 0 ;i<n;i++){
		
		if(x==0 && fork()==0){printf("procces child id %d parent id %d\n",getpid(),getppid());
			
		}else{
		wait(NULL);
		}
	
	
	}



	}



int main(int argc , char *argv[]){

	if(argc <2 ) {

		printf("welcome to amin program when exucting in terminal the program must  be in this form ./a.out [choice][space][number of childs]\n ");
		printf(" choose 1 for tree , choose 2 for a list \n" );
	
	}else{

		switch(atoi(argv[1])){

		case 1 : arbre(atoi(argv[2]));//for tree fucntion 
			 break ; 
		case 2:	chaine(atoi(argv[2]));			// for list function  
		         break ; 
	

		}

	}
	return 0; 


}








