#include<stdio.h>
#include<string.h>
struct A
{

      int price;
      char name[30];
};


int main()
{
    struct A a;
    a.price =30000;
    strcpy( a.name, "PP" );
     int *p=(int*)&a;      //non-compliant
    //int *p=(int*)&a.price; //compliant
    printf(" Price of %s is  %d ",a.name,*p);

    return 0;
}