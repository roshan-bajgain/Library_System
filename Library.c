#include<stdio.h>
#include<conic.h>

//This is the book structure
void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student
{
    /* data */
    char Name[20];
    int roll_no;
    int class[10];
    char vill[20];
    float per;
};

void main() {
    int choice;
    while (choice != 5)
    {
        printf("\t\t\t ==== STUDENT RECORD====");
        printf("\n\n\n\t\t\t\t 1. Add Student Record\n");
        printf("\t\t\t\t 2. Student Record\n");
        printf("\t\t\t\t 3. Search Student\n");
        printf("\t\t\t\t 4. Delete Record\n");
        printf("\t\t\t\t 5. Exist\n");
        printf("\t\t\t\t_____________________________________\n");
        printf("\t\t\t\t  ")
        scanf("%d", &choice)
    }
    
}



