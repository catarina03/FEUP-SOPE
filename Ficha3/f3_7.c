// PROGRAMA p7.c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char prog[20];
    sprintf(prog,"%s.c",argv[1]);
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);
    printf("Compiles a file (name is passed as argument) using gcc with the parameters -Wall -o");
    exit(0);
}