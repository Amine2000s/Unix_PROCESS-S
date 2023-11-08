#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>

/*
    code by chabi amine sif eddine 
    this one demosnstrae a chaine of three process (father -- son -- grandson )
    []--[]--[]


*/

int main() {
	//code
	
	int x = fork();
    if(x!=0){
            printf("hello form the father procees my id is %d \n",getpid());
            fflush(stdout);
         wait(NULL);
    }else{
        int y = fork();
        if(y!=0){
           printf("hello from the Son procces my pid is %d my father is %d \n",getpid(),getppid());
            fflush(stdout);
            wait(NULL);
        }else{
                       printf("hello from the Grand son procces my id is %d my father is %d \n",getpid(),getppid());
                        fflush(stdout);
                        wait(NULL);
        }
        
    }
	
	
	
	
	return 0;
}
