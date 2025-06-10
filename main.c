#include <stdio.h>

typedef struct student
{
    int uid;
    char name[40];
    int grade;
    float avg_mark;
} std;

void menu();
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void save();
void loadFile();
void saveAndExit();

int main()
{
    int option;
    menu();
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        addStudent();
        break;
    case 2:
        displayStudents();
        break;
    case 3:
        searchStudent();
    case 4:
        updateStudent();
    case 5:
        deleteStudent();
    case 6:
        save();
    case 7:
        loadFile();
    case 8:
        saveAndExit();
    default:
        break;
    }

    return 0;
}
void menu()
{
    printf("-------- Student Record Management system by Rudro --------\n\n");
    printf("1. Add Student.\n");
    printf("2. Display All Students\n");
    printf("3. Search by Student ID\n");
    printf("4. Update by Student ID\n");
    printf("5. Delete by Student ID\n");
    printf("6. Save Records to File\n");
    printf("7. Load Records from File\n");
    printf("8. Save & Exit\n");
    printf("-----------------------------------------------------------\n\n");
    printf("Enter your choice:    ");
}

void addStudent(){
printf("Done");
}


void displayStudents(){
printf("Done");
}


void searchStudent(){
printf("Done");
}


void updateStudent(){
printf("Done");
}


void deleteStudent(){
printf("Done");
}


void save(){
printf("Done");
}


void loadFile(){
printf("Done");
}


void saveAndExit(){
printf("Done");
}


