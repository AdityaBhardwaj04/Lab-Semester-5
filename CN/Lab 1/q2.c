#include <stdio.h>
#include <string.h>

struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void print_student_info_by_value(struct student_info student) {
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("DOB: %d-%d-%d\n", student.age.day, student.age.month, student.age.year);
}

void print_student_info_by_address(struct student_info *student) {
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("DOB: %d-%d-%d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    struct student_info student;

    // Read values for each member of the structure from the user
    printf("Enter roll no: ");
    scanf("%d", &student.roll_no);

    printf("Enter name: ");
    scanf("%s", student.name);

    printf("Enter CGPA: ");
    scanf("%f", &student.CGPA);

    printf("Enter DOB (dd mm yyyy): ");
    scanf("%d %d %d", &student.age.day, &student.age.month, &student.age.year);

    // Pass the populated structure to the functions
    printf("\nPrinting student info using call-by-value:\n");
    print_student_info_by_value(student);

    printf("\nPrinting student info using call-by-address:\n");
    print_student_info_by_address(&student);

    return 0;
}
