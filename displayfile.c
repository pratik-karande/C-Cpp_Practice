#include<stdio.h>
int main(){
    FILE *ptr=NULL;
    char c;

    ptr=fopen("books.txt","r");
    if(ptr==NULL){
        printf("file is empty or does not exist\n");
        exit(0);
    }
    c = fgetc(ptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(ptr);
    }
  
    fclose(ptr);
    return 0;

}