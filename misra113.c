#include<stdio.h>
struct student
{
    char grade;
    int id;
}s1;
int main()
{
    s1.grade='A';
    s1.id=65;

    char *cptr=(char *)&s1.id; // Non-Compliant code
    
   // char *cptr=(char *)&s1.grade;


    int *iptr=(int *)&s1.grade;  // Non-Compliant code

    //Compliant code
    // int *iptr=(int *)&s1.id;

     printf("Grade of student with id %d =  %c\n",*iptr,*cptr);
    
    return 0;
}