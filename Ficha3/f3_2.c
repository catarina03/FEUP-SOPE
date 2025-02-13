// PROGRAMA p2.c 

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
int main(void) {  
    write(STDOUT_FILENO,"1",1);  
    if(fork() > 0) {    
        write(STDOUT_FILENO,"2",1);    
        write(STDOUT_FILENO,"3",1);  
    } else {    
        write(STDOUT_FILENO,"4",1);    
        write(STDOUT_FILENO,"5",1);  
    }  
    write(STDOUT_FILENO,"\n",1);  
    return 0; 
}
*/

//2a) Podem ser escritos 123, 145, 23, 45.
//2b) Output: 123 \n45
//2c) 

/*
int main(void) {  
    printf("1");  
    if(fork() > 0) {    
        printf("2");    
        printf("3");  
    } else {    
        printf("4");    
        printf("5");  
    }  
    printf("\n");  
    return 0; 
}
*/

// Output: 123 \n145
//Tem haver com o buffer (?)

//2d) 

int main(void) {  
    printf("1\n");  
    if(fork() > 0) {    
        printf("2");    
        printf("3");  
    } else {    
        printf("4");    
        printf("5");  
    }  
    printf("\n");  
    return 0; 
}

//Output: 1 \n23 \n45
