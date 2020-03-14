//Exercicio 7

#include <stdlib.h>
#include <stdio.h>

void func1(){
    printf("Executing exit handler 1!\n");
}

void func2(){
    printf("Executing exit handler 2!\n");
}

int main(int argc, char *argv[])
{
    atexit(func1);
    atexit(func2);
    printf("Main done!\n");
    return 0;
}

//7b) Executa exit handler pela ordem inversa do registo
//(primeiro o exit handler 2 e depois o exit handler 1)
//É possivel instalar um handler mais do que uma vez.
//Se se fizer uma chamada abort(), nenhum dos handler é executado
//
//"Unlike exit() function, abort() may not close files that are open. 
//It may also not delete temporary files and may not flush stream buffer. 
//Also, it does not call functions registered with atexit()."
//
//Se um dos handlers terminar com exit() acontece o mesmo, pois 
//quer ao retornar normalmente, quer a terminar com exit(), 
//temos que "passar" na mesma por todos os exit handlers, pois a 
//funcao exit() é sempre chamada (implicitamente ou explicitamente)
