//Exercicio 8

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

//8a)
/*
int main(int argc, char *argv[])
{
    bool done = false;
    int number = atoi(argv[2]);
    int counter = 1;

    srand(time(0));
    while(!done) {
        int random_no = rand()%atoi(argv[1]);
        printf("%i : %i\n", counter, random_no);
        if (number == random_no){
            done = true;
        }
        counter++;
    }
    return 0;
}
*/

//8b)
int main(int argc, char *argv[])
{
    clock_t start, end;
    struct tms t;
    long ticks;

    start = times(&t);
    ticks = sysconf(_SC_CLK_TCK);

    bool done = false;
    int number = atoi(argv[2]);
    int counter = 1;

    srand(time(0));
    while(!done) {
        int random_no = rand()%atoi(argv[1]);
        printf("%i: %i  ", counter, random_no);
        if (number == random_no){
            done = true;
        }
        counter++;
    }

    end = times(&t);

    printf("\nClock ticks: %lf\n", (double) end-start/ticks);
    printf("User:\n");
    printf("Real time: %4.4f\n", (double) t.tms_utime/ticks);
    printf("CPU time: %4.4f\n", (double) t.tms_utime);
    printf("System:\n");
    printf("Real time: %4.4f\n", (double) t.tms_stime/ticks);
    printf("CPU time: %4.4f\n", (double) t.tms_stime);

    return 0;
}

