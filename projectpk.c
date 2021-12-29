#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
struct player {  
    char sID[10];
    char cPass[100];
    char cName[100];
}p;  
  
void login();  
void Register();  
void forgetPass();
void deleteAcc();
void start();

void main()
{
    char cOpt;
    printf("\n***WELCOME TO QUIZ GAME***\nAlready a user? To login enter 'L'\nNew to the game? To register enter 'R'\nForgot user ID or Password? Enter 'F'\nTo delete your acccount enter 'D'\nTo exit the game enter 'E'\n");
    scanf("%s",cOpt);

    switch (cOpt)
    {
    case 'L':
       
        login();
        break;
    case 'R':
        Register();
        break;
    case 'F':
        forgetPass();
        break;
    case 'E':
        exit(0);
        break;

    default:
        printf("Wrong input");
        break;
    }
}

void login()
{   
    
    int found;
    found = 0;
    printf("\nlogin to your account\n");
    printf("Enter your user ID: ");
    scanf("%s", &p.sID);
    printf("Enter your password: ");
    scanf("%s", &p.cPass);
    FILE *file = fopen("loginfile.txt", "r"); 
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        char *s;
        s = strstr(line, p.sID); 
        if (s != NULL)                
        {
           s= strstr(line, p.cPass);
           if(s!=NULL){
               found=1;
               break;
           }
        }
        
    }
    fclose(file);
    if (found == 1)
    {
        printf("\nyou've logged in successfully!!\n");
      //  start();

    }
    else
    {
        printf("\nIncorrect details\n");
        main(1);
    }
}
 void Register(){
    
    printf("Register your account\n");
    printf("Enter your name: ");
    scanf("%s", &p.cName);
    printf("\nEnter user ID: ");
    scanf("%s", &p.sID);
    printf("\nEnter password: ");
    scanf("%s", &p.cPass);
    FILE *fptr;
    fptr = fopen("loginfile.txt", "a+");
    fprintf(fptr, "\n%s\t%s\t%s", p.cName, p.sID, p.cPass);
    fclose(fptr);

}
void forgetPass(){
    char inp;
    int found;
    char newPass1[100];
    char newPass2[100];
    printf("Want to reset password? Enter 'Y'\nTo go back enter 'N'\n");
    scanf("%d",inp);
    if(inp=="N"){
        printf("*****Reset Password*****\nEnter your user ID: ");
        scanf("%s",&p.sID);
        printf("\nEnter your previous password: ");
        scanf("%s", &p.cPass);
        printf("\nEnter your New Password: ");
        scanf("%s",&newPass1);
        printf("\nconfirm new Password: ");
        scanf("%s",&newPass2);
        if(newPass1!=newPass2){
            printf("Enter same password to confirm and change");
        }
        FILE *file = fopen("loginfile.txt", "r"); 
        char line[256];

         while (fgets(line, sizeof(line), file))
        {
        char *s;
        s = strstr(line, p.sID); 
        if (s != NULL)                
        {
           s= strstr(line, p.cPass);
           if(s!=NULL){
               fprintf(file,"%s",newPass2);
               break;
           }
        }
        
        }
    fclose(file);
    }
}

