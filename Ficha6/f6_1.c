// PROGRAMA p01.c

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

//1a)
/*
void * thrfunc(void * arg)
{
    int i;

    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);
    return NULL;
}

int main()
{
    pthread_t ta, tb;
    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}
*/

//1b)
void * thrfunc(void * arg)
{
    int i;

    //char
    //fprintf(stderr, "Starting thread %s\n", (char *) arg);
    //for (i = 1; i <= NUMITER; i++) write(STDERR, arg, 1);
    //return NULL;

    //int
    int value = * (int *) arg;
    fprintf(stderr, "Starting thread %d\n", value);
    //printf("%d\n%d\n%d\n",value,value,value);  //Why?
    for (i = 1; i <= NUMITER; i++) write(STDERR,&value,sizeof(value));
    return NULL;
}

int main()
{
    pthread_t ta, tb;
    //char c1 = '1', c2 = '2';
    int i1 = 1, i2 = 2;

    //char
    //pthread_create(&ta, NULL, thrfunc, (void *) &c1);
    //pthread_create(&tb, NULL, thrfunc, (void *) &c2);
    
    //int
    pthread_create(&ta, NULL, thrfunc, (void *) &i1);
    pthread_create(&tb, NULL, thrfunc, (void *) &i2);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}
