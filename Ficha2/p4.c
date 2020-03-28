#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 512


//4a)
/*
int main(void)
{
 int fd1, student_no, bytes = 0;
 char buffer[BUFFER_SIZE], question[] = "How many students: ";
 char student_no_str[3];
 
 fd1 = open("student_records.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
 if (fd1 == -1) {
  return 1;
 }

 write(STDOUT_FILENO, question, strlen(question));
 read(STDIN_FILENO, student_no_str, 3);
 student_no = atoi(student_no_str);
 for (int i = 0; i < student_no; i++){
   write(STDOUT_FILENO, "Name: ", 6);
   bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
   write(fd1, buffer, bytes);
   write(STDOUT_FILENO, "Grade: ", 7);
   bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
   write(fd1, buffer, bytes);
 }

  close(fd1);
  return 0;
}
*/

//4b)Porque é que nao pode ser mostrado recorrendo a cat?
typedef struct Student{
  char name[50];
  int grade;
}Student;

int main(void)
{
 int fd1;
 unsigned student_no =0;
 Student student[100];
 Student s;
 
 fd1 = open("student_records_b.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
 if (fd1 == -1) {
  return 1;
 }

 printf("How many students: ");
 scanf("%u", &student_no);

 for (int i = 0; i < student_no; i++){
   printf("Name: ");
   scanf("%s", s.name);
   printf("Grade: ");
   scanf("%i", &s.grade);
   
   student[i] = s;
 }

 for (int j = 0; j < student_no; j++){
  write(fd1, &student[j],sizeof(Student));
 }

  close(fd1);
  return 0;
}