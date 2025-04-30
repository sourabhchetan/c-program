#include <stdio.h>

struct Employee {
    int empid;
    char name[50];
    float salary;
    int age;
};

int main() {
    struct Employee employees[50];
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].empid);
        printf("Employee Name: ");
        scanf(" %[^\n]s", employees[i].name); 
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Age: ");
        scanf("%d", &employees[i].age);
    }

    printf("\nEmployees with salary greater than 15000:\n");
    printf("EmpID\tName\t\tSalary\t\tAge\n");
    for (int i = 0; i < n; i++) {
        if (employees[i].salary > 15000) {
            printf("%d\t%s\t\t%.2f\t\t%d\n", employees[i].empid, employees[i].name, employees[i].salary, employees[i].age);
        }
    }

    return 0;
}