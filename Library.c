#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

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

void booksList() {
    system("cls");
    printf("\t\t\t\t\t\t\t\t<== Avaialable Book ==>\n\n");
    printf("%-10s %-30s %s\t\t\t\t\t\t %s\t\t\t\n", "Book id","Book Name", "Author", "Date");
    fp = fopen("books.txt","rb");
    while (fread(&b,sizeof(b),1,fp)== 1)
    {
        printf("%-10d %-30s %-20s %s\n\n",b.id, b.bookName, b.authorName, b.date);
    }
    fclose(fp);
    
}

void del() {
    int id, f=0;
    system("cls");
    printf("<== Remove Books ==>\n\n");
    printf("Enter book id to remove");
    scanf("%d", id);
    FILE *ft;
    fp= fopen("books.txt","rb");
    ft = fopen("temp.txt","wb");
    
    while(fread(&b,sizeof(b),1,fp) == 1) {
        if (id == b.id) {
            f = 1;
        } else {
            fwrite(&b,sizeof(b),1,ft);
        }
    }
    if(f==1) {
        printf("\n\n Delete Successfully");
    } else {
        printf("\n\n Record not found");
    }
    fclose(fp);
    fclose(ft);
    remove("books.txt");
    rename("temp.txt","books.txt");
}

int main () {
    int ch;
    while (1)
    {
        /* code */
        system("cls");
        printf("<=== Library Management System ===>\n");
        printf("1. Add Book \n");
        printf("2. Books list \n");
        printf("3. Remove Book \n");
        printf("4. Issued Book \n");
        printf("5. List Issued book \n");
        printf("0. Exit \n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
           case 0:
             exit(0);

          case 1: 
            addBook();
            break;

           case 2:
           booksList();
           break;


          default:
            printf("Invalid choice... \n\n");
        }
            printf("Press any key to continue...");
            getch();
    }
    return 0;
}

