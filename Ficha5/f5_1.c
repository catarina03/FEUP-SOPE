#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

//1a)
/*
int main(void)
{
    int fd[2];
    pid_t pid;

    //fd[0] - file aberto para leitura/recetor
    //fd[1] - file aberto para escrita/emissor

    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
    if ( (pid = fork()) < 0) {
        fprintf(stderr, "fork error\n");
        exit(2);
    }

    else if (pid > 0) { //pai
        int no1, no2;

        printf("Write two numbers:\n");
        printf("x: "); scanf("%i", &no1);
        printf("y: "); scanf("%i", &no2);

        close(fd[0]); //fecha lado receptor do pipe
        write(fd[1], &no1, sizeof(int));
        write(fd[1], &no2, sizeof(int));
    } else { //filho
        int no_1, no_2;

        close(fd[1]); //fecha lado emissor do pipe

        read(fd[0], &no_1, sizeof(int));
        read(fd[0], &no_2, sizeof(int));

        printf("x + y = %i\n", no_1+no_2);
        printf("x - y = %i\n", no_1-no_2);
        printf("x * y = %i\n", no_1*no_2);
        if (no_2 != 0){
            printf("x / y = %f\n", (double) no_1/no_2);
        }
        else {
            printf("Division by 0 is impossible\n");
        }

        close(fd[0]);
    }
    exit(0);
}
*/


//1b)
/*
int main(void)
{
    typedef struct Number{
        int x;
        int y;
    }Number;

    int fd[2];
    pid_t pid;

    //fd[0] - file aberto para leitura/recetor
    //fd[1] - file aberto para escrita/emissor

    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
    if ( (pid = fork()) < 0) {
        fprintf(stderr, "fork error\n");
        exit(2);
    }

    else if (pid > 0) { //pai
        Number n_pai;

        printf("Write two numbers:\n");
        printf("x: "); scanf("%i", &n_pai.x);
        printf("y: "); scanf("%i", &n_pai.y);

        close(fd[0]); //fecha lado receptor do pipe
        write(fd[1], &n_pai, 2*sizeof(int));
    } else { //filho 
        Number n;

        close(fd[1]); //fecha lado emissor do pipe

        read(fd[0], &n, 2*sizeof(int));
        printf("x + y = %i\n", n.x+n.y);
        printf("x - y = %i\n", n.x-n.y);
        printf("x * y = %i\n", n.x*n.y);
        if (n.y != 0){
            printf("x / y = %f\n", (double) n.x/n.y);
        }
        else {
            printf("Division by 0 is impossible\n");
        }

        close(fd[0]);
    }
    exit(0);
}
*/

//1c)
int main(void)
{
    int fd[2];
    pid_t pid;

    //fd[0] - file aberto para leitura/recetor
    //fd[1] - file aberto para escrita/emissor

    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
    if ( (pid = fork()) < 0) {
        fprintf(stderr, "fork error\n");
        exit(2);
    }

    else if (pid > 0) { //pai
        char no1[10], no2[10];

        printf("Write two numbers:\n");
        printf("x: "); scanf("%s", no1);
        printf("y: "); scanf("%s", no2);

        close(fd[0]); //fecha lado receptor do pipe
        write(fd[1], no1, sizeof(no1));
        write(fd[1], no2, sizeof(no2));
    } else { //filho
        char no_1[10], no_2[10];

        close(fd[1]); //fecha lado emissor do pipe

        read(fd[0], &no_1, sizeof(no_1));
        read(fd[0], &no_2, sizeof(no_2));

        int int1 = atoi(no_1);
        int int2 = atoi(no_2);

        printf("x + y = %i\n", int1+int2);
        printf("x - y = %i\n", int1-int2);
        printf("x * y = %i\n", int1*int2);
        if (int2 != 0){
            printf("x / y = %f\n", (double) int1/int2);
        }
        else {
            printf("Division by 0 is impossible\n");
        }

        close(fd[0]);
    }
    exit(0);
}