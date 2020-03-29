#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

//9a)
/*
int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    int status;
    if (argc != 2) {
        printf("usage: %s dirname\n",argv[0]);
        exit(1);
    }
    pid=fork();
    if (pid > 0){
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
        wait(&status);
        printf("exit code: %d\n", status);
    }
    else if (pid == 0){
        execlp("ls", "ls", "-laR", NULL);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}
*/

//9b)
int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    int status;
    if (argc != 2) {
        printf("usage: %s dirname\n",argv[0]);
        exit(1);
    }
    pid=fork();
    if (pid > 0){
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
        wait(&status);
        printf("exit code: %d\n", status);
        if (WIFEXITED(status)){
            printf("Son finished normally\n");
        }
        if (WIFSIGNALED(status)){
            printf("Son finished abnormally\n");
        }
    }
    else if (pid == 0){
        execlp("ls", "ls", "-laR", NULL);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}