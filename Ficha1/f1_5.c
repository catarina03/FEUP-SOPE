#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//5a)
/*
int main(int argc, char *argv[], char *envp[]){
    while(*envp){
        printf("%s\n",*envp++);
    }
    return 0; 
} 
*/

//5b)
/*
int main(int argc, char *argv[], char *envp[]){
    char *token;
    char delim[] = "=";
    
    while(*envp){
        token = strtok(*envp, delim);
        if (!strncmp(token, "USER", 5)){
            token = strtok(NULL, delim);
            printf("Hello %s!\n", token);
        }
        envp++;
    }
    return 0; 
} 
*/

//5c)
/*
int main(int argc, char *argv[], char *envp[]){  
    printf("Hello %s!\n", getenv("USER"));
    return 0; 
} 
*/

//5d)
//Para criar uma variavel de ambiente com comandos da shell basta 
//escrever $ USER_NAME="Catarina Fernandes" e depois $ export USER_NAME
int main(int argc, char *argv[], char *envp[]){  
    printf("Hello %s!\n", getenv("USER_NAME"));
    return 0; 
} 



