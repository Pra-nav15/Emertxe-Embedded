#include<stdio.h>
typedef struct Student
{
    char name[100];
    int roll_no;
    float marks;
}Student;
int main()
{
    int n;
    scanf("%d", &n);
    Student s[n];
    for (int i = 0;i < n;i++)
    {
        scanf("%s %d %f", s[i].name, &s[i].roll_no, &s[i].marks);
    }
    for (int i = 0;i < n;i++)
    {
        printf("Details of student %d\n", i + 1);
        printf("Name : %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].roll_no);
        printf("Marks : %f\n", s[i].marks);
        printf("\n");
    }
    return 0;
}