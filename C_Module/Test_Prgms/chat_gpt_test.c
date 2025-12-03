#include<stdio.h>
typedef struct Students
{
    char name[20];
    float marks;
}Students;
int main()
{
    Students s[5];
    int i,j;
    printf("Enter the Student Details :\n");
    for (i = 0;i < 5;i++)
    {
        scanf("%s %f", s[i].name, &s[i].marks);
    }
    float largest = 0;
    for (i = 0;i < 5;i++)
    {
        if (s[i].marks > largest)
        {
            largest = s[i].marks;
            j = i;
        }
    }
    printf("The Largest marks is %g\n", largest);
    printf("Topper's Name is %s\n", s[j].name);
    return 0;

}