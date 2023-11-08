#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>


/*
    code by chabi amine sif eddine
    this one demosnstrae a tree of a father  process and tow sons who have 2 sons each like this :

        []
        ||
    []--||--[]
    ||      ||
    []      []
    ||      ||
    []      []

*/


int main() {
	//code


	int x ,y ;
	x=fork();
	y=fork();
    /*
    *x=0 means that we are in the first child process
    *
    */
	if(x==0 && y!=0){
	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid(),x);
        fflush(stdout);
	    int z =fork();
        wait(NULL);
	    if(z==0 && x==0 && y!=0){
	        	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());

	        	    int f= fork();
	        	    wait(NULL);
	        	    if(f==0 &&z==0 && x==0 && y!=0){
                        	        	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());

	        	    }
	    }

	}

    if(y==0 && x!=0){
        printf("i am the child no %d , my father pid is %d \n",getpid(),getppid(),y);
        fflush(stdout);

       // int z = fork();
       int z =fork();
        wait(NULL);
	    if(z==0 && x!=0 && y==0){
	        	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());
                    wait(NULL);
	        	    int f= fork();
	        	    if(f==0 &&z==0 && x!=0 && y==0)
                    {
                        	        	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());

                    }
	    }

    }

    if(x!=0 && y!=0){
        wait(NULL);
        printf("i am actually the father and my sons x and y are : %d and %d \n",x,y);

    }

//	printf(" x is %d / y is %d \n ",x,d)
	return 0;
}
