#include <stdio.h>
#include <string.h>


//10a)
/*
int main(int argc, char *argv[]){
    char *token;
    char delim[] = " ";
    char command_line[256];
    
    fgets(command_line, 256, stdin);

    token = strtok(command_line, delim);
    while(token != NULL){
        printf(" %s ", token);
        token = strtok(NULL, delim);
    }
    return 0; 
} 
*/

//10b)
/*
int main(int argc, char *argv[]){
    char *token;
    char delim[] = " ";
    char command_line[256];
    char *token_array[256];
    int i = 0;
    
    fgets(command_line, 256, stdin);

    token = strtok(command_line, delim);
    while(token != NULL){
        token_array[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    for (int j = 0; j < i; j++){
        printf(" %s ", token_array[j]);
    }
    return 0; 
} 
*/

//10c)
int main(int argc, char *argv[]){
    char *token;
    char delim[] = ";|";
    char command_line[256];
    char *token_array[256];
    int i = 0;
    
    fgets(command_line, 256, stdin);

    token = strtok(command_line, delim);
    while(token != NULL){
        token_array[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    for (int j = 0; j < i; j++){
        if (j == i-1){
            printf("%s", token_array[j]);
        }
        else{
            printf("%s\n", token_array[j]);
        }
    }
    return 0; 
} 