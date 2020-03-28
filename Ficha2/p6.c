#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

//6a)
/*
int main(int argc, char *argv[])
{
 DIR *dirp;
 struct dirent *direntp;
 struct stat stat_buf;
 char *str;

 if (argc != 2)
 {
  fprintf( stderr, "Usage: %s dir_name\n", argv[0]);
  exit(1);
 }

 if ((dirp = opendir( argv[1])) == NULL)
 {
  perror(argv[1]);
  exit(2);
 }

 while ((direntp = readdir( dirp)) != NULL)
 {
  if (lstat(direntp->d_name, &stat_buf)==-1)   // testar com stat()
  {
   perror("lstat ERROR");
   exit(3);
  }
  if (S_ISREG(stat_buf.st_mode)) str = "regular";
  else if (S_ISDIR(stat_buf.st_mode)) str = "directory";
  else str = "other";
  printf("%-25s - %s\n", direntp->d_name, str);
 }

 closedir(dirp);
 exit(0);
}
*/

//6b) c) d)
//O hard link tem o mesmo tamanho que o .txt original
//O symbolic link é mais leve que o .txt original

//lstat() is identical to stat(), except that if pathname is a symbolic link, 
//then it returns information about the link itself, not the file that it refers to.
int main(int argc, char *argv[])
{
 DIR *dirp;
 struct dirent *direntp;
 struct stat stat_buf;
 char *str;

 if (argc != 2)
 {
  fprintf( stderr, "Usage: %s dir_name\n", argv[0]);
  exit(1);
 }

 if ((dirp = opendir( argv[1])) == NULL)
 {
  perror(argv[1]);
  exit(2);
 }

 while ((direntp = readdir( dirp)) != NULL)
 {
  if (stat(direntp->d_name, &stat_buf)==-1)   // testar com stat()
  {
   perror("stat ERROR");
   exit(3);
  }
  if (S_ISREG(stat_buf.st_mode)) str = "regular";
  else if (S_ISDIR(stat_buf.st_mode)) str = "directory";
  else str = "other";
  printf("%-25s - %-10s -size: %-8li -i-node: %ld\n", direntp->d_name, str, stat_buf.st_size, direntp->d_ino);
 }

 closedir(dirp);
 exit(0);
}

//6e)
//Ao apagar temp.txt, não se consegue mostrar a informaçao em temp2.txt (symblic link) através do comando cat
//Output: cat: temp2.txt: No such file or directory
//Mas ainda se consegue mostrar a informaçao em temp1.txt (hard link) através do comando cat

//Ao apagar temp2.txt ainda se consegue mostrar a informaçao em temp1.txt (hard link) através do comando cat




