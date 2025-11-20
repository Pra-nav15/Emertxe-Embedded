#include<stdio.h>
struct Student {
    char name[100];
    int age;
    float total_marks;
};
int main()
{
    struct Student s1,s2;
    scanf("%s %d %f",s1.name,&s1.age,&s1.total_marks);
    scanf("%s %d %f",s2.name,&s2.age,&s2.total_marks);
    float avg=(s1.total_marks+s2.total_marks)/2.0;
    printf("Average of Marks is %g",avg);
    return 0;
}