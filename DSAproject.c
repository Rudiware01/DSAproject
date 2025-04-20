#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    int rollNo;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;


struct Student* createStudent(int rollNo, char name[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}


void addStudent() {
    int rollNo;
    char name[50];
    float marks;

    printf("Enter Roll No: ");
    scanf("%d", &rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", name); 
    printf("Enter Marks: ");
    scanf("%f", &marks);

    struct Student* newStudent = createStudent(rollNo, name, marks);

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    printf("Student added successfully.\n");
}


void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    struct Student* temp = head;
    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n", temp->rollNo, temp->name, temp->marks);
        temp = temp->next;
    }
}


void searchStudent() {
    int rollNo;
    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);

    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Found: %s | Marks: %.2f\n", temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student with Roll No %d not found.\n", rollNo);
}


void deleteStudent() {
    int rollNo;
    printf("Enter Roll No to delete: ");
    scanf("%d", &rollNo);

    struct Student* temp = head;
    struct Student* prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll No %d not found.\n", rollNo);
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student deleted successfully.\n");
}


int main() {
    int choice = 0;

    while (choice != 5) {
        printf("\n---- Student Record Menu ----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            displayStudents();
        } else if (choice == 3) {
            searchStudent();
        } else if (choice == 4) {
            deleteStudent();
        } else if (choice == 5) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
