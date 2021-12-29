#include<stdio.h>
int main(){
FILE *ptr=NULL;
ptr=fopen("books.txt","a+");
fprintf(ptr,"%s","The girl in room 105 : Chetan Bhagat      Book NO.107\n");
fclose(ptr);
return 0;
}
