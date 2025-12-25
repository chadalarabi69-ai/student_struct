#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char lastName[50];
    char firstName[50];
    Date birthDate;
    char className[10];
    char studentID[15];
} Student;

int main() {
    Student S;
    FILE *f;

    printf("Enter last name: ");
    scanf("%49s", S.lastName);

    printf("Enter first name: ");
    scanf("%49s", S.firstName);
printf("Enter birth date (dd/mm/yyyy): ");
scanf("%d/%d/%d",
      &S.birthDate.day,
      &S.birthDate.month,
      &S.birthDate.year);

    printf("Enter class name: ");
    scanf("%9s", S.className);

    printf("Enter student ID: ");
    scanf("%14s", S.studentID);

   
    f = fopen("student.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

   
    fprintf(f, "%s\n%s\n%d %d %d\n%s\n%s\n",
            S.lastName,
            S.firstName,
            S.birthDate.day,
            S.birthDate.month,
            S.birthDate.year,
            S.className,
            S.studentID);

    fclose(f);

    printf("\n✔ Information saved successfully in student.txt\n");

    return 0;
}

