// PROGRAMA p01a.c 
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

//1a)
//Se for enviado SIGINT interrompe-se a funçao sleep(), retorna 0
//SIGUSR1, retorna valor != 0;
/*
void sigint_handler(int signo) 
{   
    printf("In SIGUSR1 handler ...\n");
} 

int main(void) {
   if (signal(SIGUSR1,sigint_handler) < 0)   {     
       fprintf(stderr,"Unable to install SIGUSR1 handler\n");     
       exit(1);   
    }   
    printf("Sleeping for 30 seconds ...\n");   
    sleep(30);   
    printf("Waking up ...\n");   
    
    exit(0); 
} 
*/

/*
void sigint_handler(int signo) 
{   
    printf("In SIGINT handler ...\n");
} 

int main(void) {
   if (signal(SIGINT,sigint_handler) < 0)   {     
       fprintf(stderr,"Unable to install SIGINT handler\n");     
       exit(1);   
    }   
    printf("Sleeping for 30 seconds ...\n");   
    sleep(30);   
    printf("Waking up ...\n");   
    
    exit(0); 
} 
*/


//1b) 
/*
void sigint_handler(int signo) 
{   
    printf("In SIGINT handler ...\n");
} 

int main(void) {
    if (signal(SIGINT,sigint_handler) < 0)   {     
       fprintf(stderr,"Unable to install SIGINT handler\n");     
       exit(1);   
    }   

    if (signal(SIGINT,sigint_handler) == SIG_ERR ||
        signal(SIGUSR1, SIG_IGN) == SIG_ERR ||
        signal(SIGUSR2, SIG_IGN) == SIG_ERR)   {     
       fprintf(stderr,"Unable to ignore these signals\n");     
    }   

    printf("Sleeping for 30 seconds ...\n");   
    int time_left = sleep(30);   
    while (time_left != 0){
        time_left = sleep(time_left);
    }
    printf("Waking up ...\n");   
    
    exit(0); 
} 
*/

//1c)
void sigint_handler(int signo) 
{   
    printf("In SIGINT handler ...\n");
} 

int main(void) {
    struct sigaction act;
    act.sa_handler = sigint_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGINT, &act, NULL);

    printf("Sleeping for 30 seconds ...\n");   
    int time_left = sleep(30);   
    while (time_left != 0){
        time_left = sleep(time_left);
    }
    printf("Waking up ...\n");   
    
    exit(0); 
} 