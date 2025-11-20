#include<stdio.h>
#include<string.h>
typedef struct Employees{
    int id;
    char name[100];
    float salary;
}Company;
int listalldetails(Company emp[]);
int individualdetails(Company emp[]);
int main()
{
    int option;
    struct Employees emp[3]={{1,"Abinand",25000},{2,"Arun",35000},{3,"Akash",50000}};
    printf("1.List All Employee Details\n2.Serach a Particular Employee Details\n\tEnter the option :");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        {
           listalldetails(emp);
        }
        break;
        case 2:
        {
           individualdetails(emp);
        }
        break;
        default:
          printf("Invalid");
          return 0;
    }
}
int listalldetails(Company emp[])
{
    printf("List of Employees and their Details\n");
    for(int i=0;i<3;i++)
    {
        printf("%d %s %g\n",emp[i].id,emp[i].name,emp[i].salary);
    }
    return 0;
}
int individualdetails(Company emp[])
{
    int choice;
    printf("Search By:\n1. Name\n2. Id\n3. Salary\nEnter the option: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
           char name[100];
           scanf("%s",name);
           for(int i=0;i<3;i++)
           {
              if(strcmp(name,emp[i].name)==0)
              {
                printf("%d %s %g\n",emp[i].id,emp[i].name,emp[i].salary);
                return 0;
              }
           }
           printf("Not Found");
           return 0;
        }
        break;
        case 2:
        {
           int check;
           scanf("%d",&check);
           for(int i=0;i<3;i++)
           {
              if(check==emp[i].id)
              {
                printf("%d %s %g",emp[i].id,emp[i].name,emp[i].salary);
                return 0;
              }
           }
           printf("Not Found");
           return 0;
        }
        break;
        default:
          return 0;
    }
}