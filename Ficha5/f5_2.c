#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

//2
int main(void)
{
    int fd[2], fd2[2];
    pid_t pid;

    //fd[0] - file aberto para leitura/recetor
    //fd[1] - file aberto para escrita/emissor

    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
    if (pipe(fd2) < 0) {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }    
    if ( (pid = fork()) < 0) {
        fprintf(stderr, "fork error\n");
        exit(2);
    }

    else if (pid > 0) { //pai
        int no1, no2, r1, r2, r3, signal;
        double r4;

        printf("Write two numbers:\n");
        printf("x: "); scanf("%i", &no1);
        printf("y: "); scanf("%i", &no2);

        close(fd[0]); //fecha lado receptor do pipe
        close(fd2[1]); //fecha lado emissor do 2o pipe

        write(fd[1], &no1, sizeof(int));
        write(fd[1], &no2, sizeof(int));

        read(fd2[0], &r1, sizeof(int));
        read(fd2[0], &r2, sizeof(int));
        read(fd2[0], &r3, sizeof(int));
        read(fd2[0], &signal, sizeof(int));        

        printf("x + y = %i\n", r1);
        printf("x - y = %i\n", r2);
        printf("x * y = %i\n", r3);
        if (signal){
            read(fd2[0], &r4, sizeof(double));  
            printf("x / y = %f\n", r4);
        }
        else {
            printf("Division by 0 is impossible\n");
        }

    } else { //filho
        int no_1, no_2;

        close(fd[1]); //fecha lado emissor do pipe
        close(fd2[0]); //fecha lado recetor do 2o pipe

        read(fd[0], &no_1, sizeof(int));
        read(fd[0], &no_2, sizeof(int));

        int sum = no_1+no_2;
        int sub = no_1-no_2;
        int mul = no_1*no_2;
        double div;

        int sig = 1; 
        //0 - Invalid
        //1 - Valid
        //Valid by default

        if (no_2 != 0){
            div = (double) no_1/no_2;   
        }
        else {
            sig = 0;
        }

        write(fd2[1], &sum, sizeof(int));
        write(fd2[1], &sub, sizeof(int));
        write(fd2[1], &mul, sizeof(int));
        write(fd2[1], &sig, sizeof(int));

        if (sig){
            write(fd2[1], &div, sizeof(double));
        }
    
        close(fd[0]);
        close(fd2[1]);
    }
    exit(0);
}