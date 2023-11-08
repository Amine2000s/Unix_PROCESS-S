#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
/*
    code by chabi amine sif eddine 
    this one demosnstrae a chaine of four  process (father -- son1 -- son2 -- son 3  )
    
           [father]
              ||
              ||
    [son2]--[son3]--[son1]


*/



int main() {
	//code
	
	printf("i am the dad my id is %d \n",getpid());
	fflush(stdout);
	wait(NULL);
    int x  =fork() ;
    
    if(x==0){
        
        
     printf("yes iam the first son actually my in fact my father id is this %d \n",getppid());
     fflush(stdout);
     wait(NULL);
        
    }else{
        
        
        
        int y = fork();
        
        if(y==0){
            
            
            //    printf("yes iam the second  son actually my in fact my father id is this %d \n",getppid());
                fflush(stdout);
                wait(NULL);

        }else{
            
            
            if(y!=0){
            
                int z = fork();
                if(z==0){
                     printf("yes iam the third  son actually my in fact my father id is this %d\n",getppid());
	            fflush(stdout);

                }
            }
        }
            
        
        
      /*  printf("==============================father segemnt ");
        printf("this is my first son %d ", x );
         printf("this is my first son %d ", y );
                  printf("this is my first son %d ",z );*/


    }
    
	
	
	
	
	return 0;
}
