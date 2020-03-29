#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

//10
int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    bool file = false;
    int fd1;

    if (argc < 2 || argc > 3) {
        printf("usage: %s dirname file (file is optional)\n",argv[0]);
        exit(1);
    }

    if (argc == 3){
        file = true;
    }

    pid=fork();
    if (pid > 0)
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
    else if (pid == 0){
        if (file){
            fd1 = open(argv[2], O_WRONLY | O_CREAT, 0600);
            dup2(fd1, STDOUT_FILENO);
        }
        execlp("ls", "ls", "-laR", NULL);
        printf("Command not executed !\n");
        if (file){
            close(fd1);
        }
        exit(1);
    }
    exit(0);
}
