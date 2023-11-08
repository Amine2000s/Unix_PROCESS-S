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
	
	if(x==0 && y!=0){
	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());
	    
	    int z =fork();
	    
	    if(z==0){
	        	    printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());
                    wait(1);
                    int g = fork();
                    
                    if(g==0)printf("i am the child no %d , my father pid is %d \n",getpid(),getppid());

	    }else{
	        
	    }
	    
	}

    if(y==0 && x!=0){
        printf("iam the child no %d , my father pud is %d \n",getpid(),getppid());
        
        
        int z = fork();
        
    }
    
    if(x!=0 && y!=0){
        
        printf("i am actually the father and my sons x and y are : %d and %d \n",x,y);
        
    }
	
//	printf(" x is %d / y is %d \n ",x,d)
	return 0;
}
