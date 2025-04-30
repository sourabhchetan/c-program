#include<stdio.h>

struct student {
    char name[50];
    int rollno;
    float marks;
};

float avg(struct student x[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i].marks;
    }
    return sum / n;
}

int main() {
    struct student s[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter student name: ");
        scanf("%s", s[i].name);
        printf("Enter student roll no: ");
        scanf("%d", &s[i].rollno);
        printf("Enter student marks: ");
        scanf("%f", &s[i].marks);
    }

    float a = avg(s, 10);
    printf("Average of 10 students = %f\n", a);

    return 0;
}