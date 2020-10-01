#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

/*
//3a)
int value = 0; //0 - increments the number
               //1 - decrements the number

void sigusr_handler(int signo) {
    printf("Entering SIGUSR handler");
    if (signo == SIGUSR1){
        value = 0;
    }
    if (signo == SIGUSR2){
        value = 1;
    }
    printf("Exiting SIGUSR handler");
}

int main(void) {
    struct sigaction action;
    int v = 0;

    action.sa_handler = sigusr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    printf("ola\n");

    if (sigaction(SIGUSR1,&action,NULL) < 0)
    {
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");
        exit(1);
    }
    if (sigaction(SIGUSR2,&action,NULL) < 0)
    {
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");
        exit(1);
    }

    while(1){
        printf("%i", v);
        sleep(1);
        v = v + 1;
        if (value == 1){
            v -= 1;
        }
    }

    exit(0);
}
*/

int aux =1;

void usr_handler(int signo){
    if(signo == SIGUSR1){
        printf("Increasing ...\n");
        aux++;
    }
    else if(signo == SIGUSR2){
        printf("Decreasing ...\n");
        aux--;
    }
}   

int main(){
    struct sigaction action;
    
    sigemptyset (&action.sa_mask);
    action.sa_handler= usr_handler;
    action.sa_flags= 0;
    if (sigaction(SIGUSR1,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");//case of error     
        exit(1);   
    }   
    if (sigaction(SIGUSR2,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");//case of error     
        exit(1);   
    }   
    while(1){                   
        sleep(1);
        printf("v = %d\n",aux);
    }
    exit(0);
}