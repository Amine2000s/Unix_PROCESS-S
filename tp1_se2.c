#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>







int main(int argc , char* argv[]){



	/*
	lets start by the process that creat three childs 
	*/
	printf("debut do tp , id est %d \n",getpid());
	int i=0;	
        int x = fork();
	for( i=0;i<atoi(argv[1]);i++){
	

                if(x==0 && fork()==0){printf("procces id %d , parent id %d \n",getpid(),getppid());
		    
		    for(int j=0;j<3;j++){
		      if(fork()==0){printf("grandson process id %d , parent id %d \n",getpid(),getppid());
		      exit(0);
		      }else{wait(NULL);}
		    
		    }
		    
		    
		}else{
		wait(NULL);
		}
		}
		}
		/*if(x==0){
		
		
		  printf("procces id %d from prent %d\n",getpid(),getppid() );
		  
		  for(int j;j<3;j++){
		  
		    if(fork()==0){
		    
		    printf("child procces id %d , parent id %d \n",getpid(),getppid());
		    exit(0);
		    }else{ wait(NULL); }
		}
		
		
		}else{
		wait(NULL);
		}



		}

	}*/











