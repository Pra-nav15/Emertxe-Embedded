/* #include<stdio.h>
#include<string.h>

struct Students
{
    int id;
    char name[100];
    float salary;
}s1,s2;
int main()
{
    s1.id=1;
    strcpy(s1.name,"Vivek");
    s1.salary=245.03;
    printf("%d %s %g",s1.id,s1.name,s1.salary);
} */
/* #include<stdio.h>
#include<string.h>

struct Students
{
    int id;
    char name[100];
    float salary;
};
int main()
{
    struct Students s1 = {1,"Vivek",5752.25};
    struct Students *sptr=&s1;
    // printf("%d %s %g",(*sptr).id,(*sptr).name,(*sptr).salary);
    printf("%d %s %g",sptr->id,sptr->name,sptr->salary); // using pointers concept
} */
#include<stdio.h>
#include<string.h>

typedef struct Students//old datatype
{
    int id;
    char name[100];
    float salary;
}Student; // new data type so Student will be the data type which is struct Students
int main()
{
    Student s1 = {1,"Vivek",5752.25};
    Student *sptr=&s1;
    // printf("%d %s %g",(*sptr).id,(*sptr).name,(*sptr).salary);
    printf("%d %s %g",sptr->id,sptr->name,sptr->salary); // using pointers concept
}