#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

//4a)
int main(void) {  
    pid_t pidFather;

    pidFather = fork();
    if(pidFather > 0) {   
        sleep(1); 
        printf("world\n");    
    } else {    
        printf("Hello ");    
    }  
    return 0; 
}


//4b)
/*
int main(void) {  
    if(fork() > 0) {    
        printf("Hello ");    
    } else {    
        printf("world!\n");    
    }  
    return 0; 
}
*/