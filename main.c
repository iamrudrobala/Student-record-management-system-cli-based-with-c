#include <stdio.h>

typedef struct student
{
    int uid;
    char name[40];
    int grade;
    float avg_mark;
} std;

void menu();

int main()
{
    menu();
    return 0;
}
void menu()
{
    printf("-------- Student Record Management system by Rudro --------\n\n");
    printf("1. Add Student.\n");
    printf("2. Display All Students\n");
    printf("3. Search\n");
    printf("4. Update \n");
    printf("5. Delete\n");
    printf("6. Save Records to File\n");
    printf("7. Load Records from File\n");
    printf("8. Exit\n");
    printf("-----------------------------------------------------------\n\n");
    printf("Enter your choice:    ");
}