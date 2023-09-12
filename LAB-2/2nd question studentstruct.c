#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct student {
    char name[50];
    int roll_no;
    char grade;
};

void readStudents(struct student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Roll No: ");
        scanf("%d", &arr[i].roll_no);
        printf("Grade: ");
        scanf(" %c", &arr[i].grade);
    }
}

void displayStudents(struct student arr[], int n) {
    printf("Student Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", arr[i].name);
        printf("Roll No: %d\n", arr[i].roll_no);
        printf("Grade: %c\n", arr[i].grade);
        printf("\n");
    }
}

void sortStudentsByRoll(struct student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                // Swap the two students
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_students;
    struct student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    if (num_students > MAX_STUDENTS) {
        printf("Exceeded maximum number of students.\n");
        return 1;
    }

    readStudents(students, num_students);

    printf("\nUnsorted Student Details:\n");
    displayStudents(students, num_students);

    sortStudentsByRoll(students, num_students);

    printf("\nSorted Student Details by Roll Number:\n");
    displayStudents(students, num_students);

    return 0;
}
