#include<stdio.h>
#include<strings.h>
#define MAX 100
int main(){
    FILE *ptr=NULL;
    ptr=fopen("books.txt","w");
    fprintf(ptr,"%s","      BOOK NAME : AUTHOR NAME                BOOK NO.\n");
    fprintf(ptr,"%s","Long walk to freedom : Nelson Mandela     Book NO.100\n");
    fprintf(ptr,"%s","Hello World : Pablo picasso               Book NO.102\n");
    fprintf(ptr,"%s","Best friends for life : Shalini Mehta     Book NO.103\n");
    fprintf(ptr,"%s","Before we met : Harish Chand              Book NO.104\n");
    fprintf(ptr,"%s","Half girlfriend : Chetan Bhagat           Book NO.105\n");
    fprintf(ptr,"%s","Twilight : Hermoine Stella                Book NO.106\n");
    fclose(ptr);
    //To enter a new book to record
    // char str[MAX];
    // printf("Enter new book\n");
    // scanf("%^\t%c",&str);
    // // FILE *ptr1=NULL;
    // // ptr1=fopen("books.txt","a");
    // // fprintf(ptr,"%s\n",str);
    // FILE *ptr1;
    // ptr1=fopen("books.txt","a+");
    // fprintf(ptr1,"%s",str);
    // fclose(ptr1);
    return 0;
}