#include <stdio.h>

struct student {
    int id;
    int age;
    char name[30];
    float salary;
};

int main()
{
    struct student s[5];
    for(int i=1;i<=5;i++)
    {
        scanf("%d %d %s %f\n",&s[i].id,&s[i].age,s[i].name,&s[i].salary);
    }
    for (int i = 1; i <=5; i++) {
        printf("%-10d %-10d %-20s %f\n",s[i].id, s[i].age, s[i].name, s[i].salary);
    }
}

