#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct books
{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}b;

struct student
{
    int id; 
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
}s;

FILE *fp;

int main () {
    int ch;
    while (1)
    {
        /* code */
        system("cls");
        printf("<=== Library Management System ===>");
        printf("1. Add Book \n");
        printf("2. Books list \n");
        printf("3. Remove Book \n");
        printf("4. Issued Book \n");
        printf("5. List Issued book \n");
        printf("0. Exit \n\n");
        printf("Enter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0;
            /* code */
            exit(0);
        case 1: 
          addBook();
          break;

        case 2:
          bookslist();
          break;

        case 3:
          del();
          break;  

        case 4;
          issueBook();
          break;

        case 5;
          issueList();
          break;
        
        default:
          printf("Invalid choice... \n\n");
        }
          printf("Predd any key to continue...");
    }
    return 0;
}

void addBook() {
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate,"%02d/%02d/%02d",tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("books.txt","ab");

    printf("Enter book id: ");
    scanf("%d", &b.id);

    printf("Enter book name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("Enter author name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("Book added Successfully");

    fwrite(&b, sizeof(b),1,fp);
    fclose(fp);
}









