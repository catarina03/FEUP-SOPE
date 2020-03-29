// PROGRAMA p1.c

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int global=1; 

int main(void) {
    int local = 2;   
    if(fork() > 0) {     
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global++;     
        local--;   
    } else {
        printf("PID = %d; PPID = %d\n", getpid(), getppid());     
        global--;     
        local++;   
    }   
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);   
    return 0; 
} 

//1.a) O porcesso pai é o primeiro processo (a variavel global aumenta e a local diminui)
//O processo filho é o segundo. 
//A forma de comunicação é através de uma variável global e de uma local ??
//E faz-se no sentido pai->filho ??

//1.b) Como há criação de novos processos, o id dos processos vai mudando (aumentando)