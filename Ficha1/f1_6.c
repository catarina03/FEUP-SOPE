// PROGRAMA p6a.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256

//6a)
/*
int main(void)
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )
    {
        exit(1);
    }
    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL )
    {
        exit(2);
    }
    while( ( fgets( buf, INT_MAX, src ) ) != NULL )
    {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
    return 0;
}
*/

//6b) Nao ha nenhum ficheiro chamado infile.txt ou outfile.txt

//6c) Usando o comando echo $? verifica-se que o codigo de terminaçao e 1

//6d)
/*
int main(void)
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )
    {
        //strerror(1);
        perror("Coudn't open intext.txt file in reading mode");
        exit(1);
    }
    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL )
    {
        //strerror(2);
        perror("Couldn't open outfile.txt in writing mode");
        exit(2);
    }
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
    {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
    return 0;
}
*/

//6e)
/*
int main(void)
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )
    {
        printf("%i\n", errno);
        exit(1);
    }
    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL )
    {
        printf("%i\n", errno);
        exit(2);
    }
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
    {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
    return 0;
}
*/

//6f) Agora que há um ficheiro infile.txt o programa corre como
//é suposto, sendo copiado o conteúdo do ficheiro infile.txt para
//outfile.txt.

//6g)
//Quando se executa o programa sem argumentos, o programa imprime
//14 no ecra (errno == 14 significa bad address)
/*
int main(int argc, char *argv[])
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if ( ( src = fopen( argv[1], "r" ) ) == NULL )
    {
        printf("%i\n", errno);
        exit(1);
    }
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL )
    {
        printf("%i\n", errno);
        exit(2);
    }
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
    {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
    return 0;
}
*/

//6h)
int main(int argc, char *argv[])
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if( argc < 3){
        printf("usage: %s file1 file2\n", argv[0]);
        exit(14);
    }
    if ( ( src = fopen( argv[1], "r" ) ) == NULL )
    {
        printf("%i\n", errno);
        exit(1);
    }
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL )
    {
        printf("%i\n", errno);
        exit(2);
    }
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
    {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
    return 0;
}
