#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void) {  
    pid_t pid, pid2;

    pid = fork();
    pid2 = fork();
    if (pid > 0 && pid2 > 0){
        sleep(2);
    }
    if (pid > 0 && pid2 == 0) { 
        printf("Hello ");  
    }
    else if (pid == 0 && pid2 > 0) {
        sleep(0.5);
        printf("my ");
    }
    else if (pid == 0 && pid2 == 0) {
        sleep(1);
        printf("friends!\n");
    } 
    return 0; 
}