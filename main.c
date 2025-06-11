#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int uid;
    char name[100];
    int grade;
    float avg_mark;
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int total_students = 0;

void menu();
void addStudent();
void displayStudents();
void saveToFile();
void loadFromFile();
void searchStudent();
void deleteStudent();

int main() {
    int choice;
    loadFromFile();

    while (1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveToFile(); break;
            case 6:
                saveToFile();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Please choose between 1-6.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n------ Student Record Management ------\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Delete Student by ID\n");
    printf("5. Save to File\n");
    printf("6. Save & Exit\n");
    printf("---------------------------------------\n");
}

void addStudent() {
    if (total_students >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[total_students].uid);
    getchar(); // clear newline

    printf("Enter Name: ");
    fgets(students[total_students].name, 100, stdin);
    strtok(students[total_students].name, "\n");

    printf("Enter Grade: ");
    scanf("%d", &students[total_students].grade);

    printf("Enter Average Mark: ");
    scanf("%f", &students[total_students].avg_mark);

    printf("Enter GPA: ");
    scanf("%f", &students[total_students].gpa);

    total_students++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (total_students == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-5s %-20s %-6s %-10s %-5s\n", "ID", "Name", "Grade", "Avg Mark", "GPA");
    for (int i = 0; i < total_students; i++) {
        printf("%-5d %-20s %-6d %-10.2f %-5.2f\n",
               students[i].uid,
               students[i].name,
               students[i].grade,
               students[i].avg_mark,
               students[i].gpa);
    }
}

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if (!fp) {
        printf("Failed to save data.\n");
        return;
    }

    for (int i = 0; i < total_students; i++) {
        fprintf(fp, "%d|%s|%d|%.2f|%.2f\n",
                students[i].uid,
                students[i].name,
                students[i].grade,
                students[i].avg_mark,
                students[i].gpa);
    }

    fclose(fp);
    printf("Data saved to students.txt\n");
}

void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if (!fp) {
        printf("No existing data found.\n");
        return;
    }

    total_students = 0; // Reset student count before loading

    while (fscanf(fp, "%d|%[^|]|%d|%f|%f\n",
                  &students[total_students].uid,
                  students[total_students].name,
                  &students[total_students].grade,
                  &students[total_students].avg_mark,
                  &students[total_students].gpa) == 5) {
        total_students++;

        if (total_students >= MAX_STUDENTS) {
            printf("Max student limit reached.\n");
            break;
        }
    }

    fclose(fp);
    printf("%d student(s) loaded from file.\n", total_students);
}
void searchStudent() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < total_students; i++) {
        if (students[i].uid == id) {
            printf("Student Found:\n");
            printf("ID: %d\nName: %s\nGrade: %d\nAvg Mark: %.2f\nGPA: %.2f\n",
                   students[i].uid,
                   students[i].name,
                   students[i].grade,
                   students[i].avg_mark,
                   students[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void deleteStudent() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < total_students; i++) {
        if (students[i].uid == id) {
            found = 1;
            for (int j = i; j < total_students - 1; j++) {
                students[j] = students[j + 1];
            }
            total_students--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

