#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define BUFFER_SIZE 1000
struct player
{
    char sID[10];
    char cPass[100];
    char cName[100];
    int jHints;
    int jScore;
    int jLine;
} p;
struct changePass
{
    char oldPass[100];
    char newPass[100];
    char newPass1[100];
    char buffer[1000];
} c;
struct count
{
    char s_Answer1[50];
    char s_category[10];
    char s_levels[10];
    int j_Qno;
    int jLineNo;
    int j_line3;
    int j_line4;
} c1;
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    // Fix: If oldWord and newWord are same it goes to infinite loop
    if (!strcmp(oldWord, newWord)) {
        return;
    }


    /*
     * Repeat till all occurrences are replaced. 
     */
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Backup current line
        strcpy(temp, str);

        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, newWord);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(str, temp + index + owlen);
    }
}
void updatePassword(char path[100],char oldWord[100],char newWord[100])
{
    FILE * fPtr;
    FILE * fTemp;
  
    char buffer[BUFFER_SIZE];

    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.txt", "w"); 
    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Replace all occurrence of word from current line
        replaceAll(buffer, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Delete original source file */
    remove(path);
 
    /* Rename temp file as original file */
    rename("replace.txt", path);

    printf("\nPassword successfully changed!!!");
}
 showHOme()
{
    char cOpt;

    printf("\n-------------------------------------\n********WELCOME TO QUIZ GAME********\n--------------------------------------\nAlready a user? To login enter 'L'\nNew to the game? To register enter 'R'\nWant to Change Password? Enter 'F'\nTo delete your acccount enter 'D'\nTo exit the game enter 'E'\n");
    
    scanf(" %c", &cOpt);
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
    case 'D':
       deleteAccountConfirmation();
       break;
    default:
        printf("Wrong input");
        break;
    }
}
int main()
{
    showHOme();
    return 0;
}

void login()
{

    int found;
    found = 0;
    printf("\nlogin to your account\n");
    printf("\nEnter your name: ");
    scanf("%s",&p.cName);
    printf("Enter your user ID: ");
    scanf("%s", &p.sID);
    printf("Enter your password: ");
    scanf("%s", &p.cPass);
    FILE *file = fopen("logindetails.txt", "r");
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        char *s;
        s = strstr(line, p.sID);
        if (s != NULL)
        {
            s = strstr(line, p.cPass);
            if (s != NULL)
            {
                found = 1;
                break;
            }
        }
    }
    fclose(file);
    if (found == 1)
    {
        printf("\nyou've logged in successfully!!\n");
        startGame();
    }
    else
    {
        printf("\nIncorrect details\n");
        showHOme();
    }
}
void Register()
{

    printf("Register your account\n");
    printf("Enter your name: ");
    scanf("%s", &p.cName);
    printf("\nEnter user ID: ");
    scanf("%s", &p.sID);
    printf("\nEnter password: ");
    scanf("%s", &p.cPass);
    FILE *fptr;
    fptr = fopen("logindetails.txt", "a+");
    fprintf(fptr, "\n%s\t%s\t%s", p.cName, p.sID, p.cPass);
    fclose(fptr);
    printf("\nYou've successfully registered!!!\n");
    // start();
}
void forgetPass()
{
    printf("Enter User ID: ");
    scanf("%s", &p.sID);
    printf("Enter previous password: ");
    scanf("%s", &c.oldPass);

    printf("Enter New password: ");
    scanf("%s", &c.newPass);
    printf("Confirm new password: ");
    scanf("%s", &c.newPass1);
    if (strcmp(c.newPass , c.newPass1)!=0)
    {
        printf("\npassword did not match!\n");
        showHOme();
    }
    else{
    char fname[100] = "logindetails.txt";
    /*  Open all required files */
    FILE *fPtr = fopen(fname, "r");

    char line[256];
    int found = 0;
    while (fgets(line, sizeof(line), fPtr))
    {
        char *s;
        s = strstr(line, p.sID);
        if (s != NULL)
        {
            s = strstr(line, c.oldPass);
            if (s != NULL)
            {
                found = 1;
                break;
            }
        }
    }
    fclose(fPtr);
    if (found == 1)
    {
        updatePassword(fname,c.oldPass,c.newPass1);
        showHOme();

    }else{
        printf("\nAccount does not exist!!!");
        showHOme();
    }
    }
}	
void removeAll(char *str, const char *toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen = strlen(str);        // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove

    for (i = 0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for (j = 0; j < toRemoveLen; j++)
        {
            if (str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */
        if (str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0')
        {
            found = 0;
        }
        /*
         * If word is found then shift all characters to left
         * and decrement the string length */
        if (found == 1)
        {
            for (j = i; j <= stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
   }
}
void deleteAcc()
{
    FILE *fPtr;
    FILE *fTemp;
    char path[] = "logindetails.txt";

    char name_toRemove[100];
    char ID_toRemove[100];
    char pass_toRemove[100];
    char buffer[1000];

    printf("\nEnter your name: ");
    scanf("%s", name_toRemove);
    printf("\nEnter your user ID: ");
    scanf("%s", ID_toRemove);
    printf("Enter your password: ");
    scanf("%s", pass_toRemove);

    /*  Open files */
    fPtr = fopen(path, "r");
    fTemp = fopen("delete.tmp", "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    /* Read line from source file and write to destination
     * file after removing given word.
     */
    while ((fgets(buffer, 1000, fPtr)) != NULL)
    {
        // Remove all occurrence of word from current line
        removeAll(buffer, name_toRemove);
        removeAll(buffer, ID_toRemove);
        removeAll(buffer, pass_toRemove);

        // Write to temp file
        fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("delete.tmp", path);

    printf("\nAccount removed successfully.");

    showHOme();
}
void  deleteAccountConfirmation(){
    char warn;
    printf("\nAre you sure you want to delete your account? (Y/N):");
   // scanf("%s",&warn);
      scanf(" %c", &warn);
    if(warn=='Y'){
        deleteAcc();
    }
    else{
        showHOme();
    }
}
void instructions()
{
    printf("***Instruction to play the game***\n");
    printf("----------------------------------\n\n");
    printf("To skip a question enter 'skip'\n ");
    printf("To take a hint enter 'H'\n");
    printf("To see score board enter 'SB'\n");
    printf("To  exit from the game enter 'exit'\n");
    printf("To go back enter 'back'\n");
    printf("To start enter 'start'\n");
}
enum LEVEL
{
    Easy = 1,
    Medium = 2,
    Hard = 3
};
enum CATEGORY
{
    HISTORY = 1,
    GEOGRAPHY = 2,
    TECHNOLOGY = 3
};
void showQuestion(int j_Q, char chCat, char chLevel)
{
    int j_line;
    if (j_Q != 1)
    {
        j_line = (j_Q - 1) * 4 + 1;
    }
    else
    {
        j_line = j_Q;
    }

    int jCat = chCat - '0';
    int jLevel = chLevel - '0';
    if (jCat == HISTORY && jLevel == Easy)
    {
        getQuestion("HistoryEasy.txt", j_line);
    }
    else if (jCat == HISTORY && jLevel == Medium)
    {
        getQuestion("HistoryMedium.txt", j_line);
    }
    else if (jCat == HISTORY && jLevel == Hard)
    {
        getQuestion("HistoryHard.txt", j_line);
    }
}
void getQuestion(char arrFileName[50], int j_line)
{
    FILE *file = fopen(arrFileName, "r");
    char line[300];
    int i = 0;
    while (fgets(line, sizeof(line), file))
    {
        i++;
        if (i == j_line)
        {
            printf("%s", line);
        }
    }
    fclose(file);
}
void showHints(int Q, char chCat, char chLevel)
{
    int j_line;
    if (Q != 1)
    {
        j_line = (Q - 1) * 4 + 3;
    }
    else
    {
        j_line = 3;
    }
    int jCat = chCat - '0';
    int jLevel = chLevel - '0';
    if (jCat == HISTORY && jLevel == Easy)
    {
        getQuestion("HistoryEasy.txt", j_line);
    }
    else if (jCat == HISTORY && jLevel == Medium)
    {
        getQuestion("HistoryMedium.txt", j_line);
    }
    else if (jCat == HISTORY && jLevel == Hard)
    {
        getQuestion("HistoryHard.txt", j_line);
    }
}
void checkAnswers(int ques, char cate, char lev, char ans)
{
    int count = 0;
    int j_line2;
    if (ques != 1)
    {
        j_line2 = (ques - 1) * 4 + 2;
    }
    else
    {
        j_line2 = 2;
    }
    int jCat = cate - '0';
    int jLevel = lev - '0';
    if (jCat == HISTORY && jLevel == Easy)
    {
        updateScore("HistoryEasy.txt", j_line2, ans);
    }
    else if (jCat == HISTORY && jLevel == Medium)
    {
        updateScore("HistoryMedium.txt", j_line2, ans);
    }
    else if (jCat == HISTORY && jLevel == Hard)
    {
        updateScore("HistoryHard.txt", j_line2, ans);
    }
}
void updateScore(char arrFileName[50], int j_line2, char ans)
{
    FILE *file = fopen(arrFileName, "r");
    char line[300];
    int i = 0;
    while (fgets(line, sizeof(line), file))
    {
        i++;
        if (i == j_line2)
        {
            if (line[0] == ans)
            {
                p.jScore++;
                //printf("score is %d",c2.jScore);
            }
        }
    }
    fclose(file);
}
void getHint()
{
    c1.j_line3 = c1.jLineNo + 1;
    FILE *file3 = fopen("playerInfo.txt", "r");
    char line[300];
    int i = 0;
    while (fgets(line, sizeof(line), file3))
    {
        i++;
        if (i == c1.j_line3)
        {
            printf("Your remaining hints are: \n");
            printf("%c \n", line[0]);
            int jHint = (int)(line[0]);
            p.jHints = jHint - '0';
            //printf("%d\n",c2.jHints);
        }
    }
    fclose(file3);
}
void getScore()
{
    c1.j_line4 = c1.jLineNo + 2;
    FILE *file4 = fopen("playerInfo.txt", "r");
    char line[300];
    int i = 0;
    while (fgets(line, sizeof(line), file4))
    {
        i++;
        if (i == c1.j_line4)
        {
            printf("Your score is: \n");
            printf("%c \n", line[0]);
            int jScore = (int)(line[0]);
            p.jScore = jScore - '0';
        }
    }
    fclose(file4);
}
void updatefinalScore()
{
    FILE *fPtr = fopen("playerInfo.txt", "r");
    FILE *fTemp;

    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    newline[0] = p.jScore + '0';

    int count;

    /* Remove extra new line character from stdin */
    fflush(stdin);

    /*  Open all required files */

    fTemp = fopen("replace.txt", "w");
    printf("file opened ");

    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;
        
        if (count == c1.j_line4)
        {
            newline[1] = '\n';
            //printf("%d newline type", c1.j_line3);
            fputs(newline, fTemp);
        }

        else
        {
            fputs(buffer, fTemp);
        }
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Delete original source file */
    remove("playerInfo.txt");

    /* Rename temporary file as original file */
    rename("replace.txt", "playerInfo.txt");
}
void updateHints()
{

    FILE *fPtr = fopen("playerInfo.txt", "r");
    FILE *fTemp;

    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    newline[0] = p.jHints + '0';
    printf("Hints int  %d\n", p.jHints);
    printf("Hints %c\n", newline[0]);
    int count;

    /* Remove extra new line character from stdin */
    fflush(stdin);

    /*  Open all required files */

    fTemp = fopen("replace.txt", "w");
    printf("file opened ");
    
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;
        printf("%d Count %d\n", count, c1.j_line3);
        /* If current line is line to replace */
        if (count == c1.j_line3)
        {
            newline[1] = '\n';
            printf("%d newline type", c1.j_line3);
            fputs(newline, fTemp);
        }

        else
        {
            fputs(buffer, fTemp);
        }
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Delete original source file */
    remove("playerInfo.txt");

    /* Rename temporary file as original file */
    rename("replace.txt", "playerInfo.txt");
}
void startGame(char chCatgory, char chLevel)
{
    int jQNo;
    printf("Enter question no. out of:  \n");
    scanf("%d", &jQNo);
    if (jQNo > 3)
    {
        printf("questions are finished choose next level or category");
        printf("To  exit from the game enter exit\n");

        scanf("%s", &c1.s_Answer1);
        if( strcmp(c1.s_Answer1, "exit") == 0)
        {
            updateHints();
            updatefinalScore();
            exit(0);                                                       //check this
        }
    }
   
    showQuestion(jQNo, chCatgory, chLevel);
    printf("your hints are %d", p.jHints);
    instructions();
    printf("Input your choice: \n");
    char s_Answer[50];
    scanf("%s", &s_Answer);
    if (strcmp(s_Answer, "H") == 0)
    {
        printf("your remaining hints are %d \n", p.jHints);
        p.jHints--;
        showHints(jQNo, chCatgory, chLevel);
        char ans[50];
        scanf("%s", &ans);
        checkAnswers(jQNo, chCatgory, chLevel, ans[0]);
        startGame(c1.s_category[0], c1.s_levels[0]);
    }
    else if (strcmp(s_Answer, "exit") == 0 )
    {
        updateHints();
        updatefinalScore();
        exit(0);
    }
    else if (strcmp(s_Answer, "skip") == 0)
    {
        startGame(c1.s_category[0], c1.s_levels[0]);
    }
    else if (strcmp(s_Answer, "a") == 0 || strcmp(s_Answer, "b") == 0 || strcmp(s_Answer, "c") == 0 || strcmp(s_Answer, "d") == 0)
    {
        checkAnswers(jQNo, chCatgory, chLevel, s_Answer[0]);
        startGame(c1.s_category[0], c1.s_levels[0]);
    }
}
void chooseCategoryLevel()
{
    login();
    getHint();
    getScore();
    printf("choose category by typing number of category name\n 1-History 2-Geography 3-Technology 4-Grammer\n");

    scanf("%s", &c1.s_category);
    printf("Choose level number \n 1- Easy 2-Medium 3-Hard \n");

    scanf("%s", &c1.s_levels);
    if (c1.s_category[0] == '1' || c1.s_category[0] == '2' || c1.s_category[0] == '3' || c1.s_category[0] == '4')
    {
        if (c1.s_levels[0] == '1' || c1.s_levels[0] == '2' || c1.s_levels[0] == '3' || c1.s_levels[0] == '4')
        {
            startGame(c1.s_category[0], c1.s_levels[0]);
        }
    }
}
// int main()
// {
//     instructions();
//     char s_str2[20];
//     scanf("%s", s_str2);
//     if (strcmp(s_str2, "back") == 0)
//     {
//         printf("Are you sure you want to go back?\n");
//         printf("To confirm enter Y To cancel enter N\n");
//         char s_YN[20];
//         scanf("%s", &s_YN);
//         if (strcmp(s_YN, "Y") == 0)
//         {
//             exit(0);
//         }
//         else
//         {
//             chooseCategoryLevel();
//         }
//     }
//     else if (strcmp(s_str2, "exit") == 0)
//     {
//         printf("Are you sure you want to exit?\n");
//         printf("To confirm enter Y To cancel enter N\n");
//         char s_Exit[10];
//         scanf("%s", &s_Exit);
//         if (strcmp(s_Exit, "Y") == 0)
//         {
//             exit(0);
//         }
//         else
//         {
//             chooseCategoryLevel();
//         }
//     }
//     else if (strcmp(s_str2, "SB") == 0)
//     {
//         char c;
//         FILE *ptr;
//         ptr = fopen("playerInfo.txt", "r");
//         c = fgetc(ptr);
//         while (c != EOF)
//         {
//             printf("%c", c);
//             c = fgetc(ptr);
//         }
//         fclose(ptr);
//     }
//     else if (strcmp(s_str2, "start") == 0)
//     {
//         chooseCategoryLevel();
//     }

//     return 0;
// }