//FOLHA 2 - p2b.c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

/*
int main(int argc, char *argv[])
{
    FILE *src, *dst;
    char buf[BUFFER_SIZE];
    if ( ( src = fopen( argv[1], "r" ) ) == NULL )
    {
        exit(1);
    }
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL )
    {
        exit(2);
    }
    while( ( fgets( buf, BUFFER_SIZE, src ) ) != NULL )
    {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
    return 0;
}
*/


int main(int argc, char *argv[])
{
 int fd1, fd2, nr, nw;
 unsigned char buffer[BUFFER_SIZE];

 if (argc != 3) {
  printf("Usage: %s <source> <destination>\n", argv[0]);
  return 1;
 }
 fd1 = open(argv[1], O_RDONLY);
 if (fd1 == -1) {
  perror(argv[1]);
  return 2;
 }
 fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
 if (fd2 == -1) {
  perror(argv[2]);
  close(fd1);
  return 3;
 }
 while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) {
    if ((nw = write(fd2, buffer, nr)) <= 0 || nw != nr) {
    perror(argv[2]);
    close(fd1);
    close(fd2);
    return 4;
    }
  }
  close(fd1);
  close(fd2);
  return 0;
}


