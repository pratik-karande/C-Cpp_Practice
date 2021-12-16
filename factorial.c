#include<stdio.h>
int main(){
int j;
printf("input a number: ");
scanf("%d",&j);
int fact=1;
for(int i=1;i<=j;i++){
    fact=fact*i;
}
printf("Factorial of %d is %d",j,fact);
}