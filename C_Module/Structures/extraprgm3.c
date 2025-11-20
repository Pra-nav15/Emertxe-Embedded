#include<stdio.h>
struct Employee {
    int id;
    char name[20];
    float salary;
};
int main()
{
    struct Employee emp[3];
    for(int i=0;i<3;i++)
    {
       scanf("%d %s %f",&emp[i].id,emp[i].name,&emp[i].salary);
    }
    for(int i=0;i<3;i++)
    {
        printf("%d %s %f\n",emp[i].id,emp[i].name,emp[i].salary);
    }
    if(emp[1].salary>emp[2].salary && emp[1].salary>emp[3].salary)
    {
        printf("Employee with highest salary is %s",emp[1].name);
    }
    else if(emp[2].salary>emp[1].salary && emp[2].salary>emp[3].salary)
    {
        printf("Employee with highest salary is %s",emp[2].name);
    }
    else
    {
        printf("Employee with highest salary is %s",emp[3].name);
    }
}