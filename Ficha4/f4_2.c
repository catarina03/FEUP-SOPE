// PROGRAMA p02a.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

//2a)
//If the program has not entered the SIGINT handler it will process CTRL-C and enter the SIGINT handler
//but if we send CTRL-C many times while the program is in the handler, it will exit the handler first and 
//only then will it process the sinals, but it will process only one and ignore the rest

void sigint_handler(int signo) {
    printf("Entering SIGINT handler ...\n");
    sleep(10);
    printf("Exiting SIGINT handler ...\n");
}

void sigterm_handler(int signo) {
    printf("Entering SIGTERM handler ...\n");
    sleep(10);
    printf("Exiting SIGTERM handler ...\n");
}

int main(void) {
    struct sigaction action;
    struct sigaction action2;

    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    action2.sa_handler = sigterm_handler;
    sigemptyset(&action2.sa_mask);
    action2.sa_flags = 0;

    if (sigaction(SIGINT,&action,NULL) < 0)
    {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    if (sigaction(SIGTERM,&action2,NULL) < 0)
    {
        fprintf(stderr,"Unable to install SIGTERM handler\n");
        exit(1);
    }
    printf("Try me with CTRL-C...\n");
    while(1) pause();

    exit(0);
}

//2b)
//Using "ps -u" we can see the pid of the program we want to terminate
//After that we use "kill <pid>" 
//The output is "Terminated" which is expected, as it is the default action for that signal

//2c)
//As predicted, the program no longer terminates and the SIGTERM signal is "caught" by the handler