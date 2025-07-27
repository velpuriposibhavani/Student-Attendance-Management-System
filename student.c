#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Student
 {
    int roll;
    char name[50];
    int presentDays; 
 };
struct Student students[MAX];
int count = 0;
void addStudent();
void markAttendance();
void viewAttendance();
int main() {
    int choice;
    while (1)
   {
        printf("\n===== Student Attendance Management =====\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                markAttendance();
                break;
            case 3:
                viewAttendance();
                break;
            case 4:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
void addStudent() {
    if (count >= MAX) 
	{
        printf("Cannot add more students.\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]", students[count].name);
    students[count].roll = count + 1;
    students[count].presentDays = 0;

    printf("Student added. Roll No: %d\n", students[count].roll);
    count++;
}
void markAttendance() {
    int roll;
    char status;
    printf("Enter Roll Number to mark attendance: ");
    scanf("%d", &roll);
    if (roll <= 0 || roll > count) {
        printf("Invalid roll number.\n");
        return;
    }
    printf("Mark Present (P) or Absent (A): ");
    scanf(" %c", &status);
    if (status == 'P' || status == 'p') {
        students[roll - 1].presentDays++;
        printf("Attendance marked as Present.\n");
    } else if (status == 'A' || status == 'a') {
        printf("Attendance marked as Absent.\n");
    } else {
        printf("Invalid input.\n");
    }
}
void viewAttendance() 
{
    printf("\n--- Attendance Record ---\n");
    printf("Roll\tName\t\tPresent Days\n");
    printf("--------------------------------------\n");
    int i;
    for ( i = 0; i < count; i++) 
	{
        printf("%d\t%-15s%d\n", students[i].roll, students[i].name, students[i].presentDays);
    }
}

