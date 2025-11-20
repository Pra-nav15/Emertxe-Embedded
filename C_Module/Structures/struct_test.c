#include<stdio.h>
struct Student{
    int id;
    char name[10];
}s1;
int main()
{
    struct Student *ptr=&s1;
    scanf("%d %s",&ptr->id,ptr->name);
    printf("Using -> Operator %d %s\n",ptr->id,ptr->name);
    printf("Using * Operator %d %s",(*ptr).id,(*ptr).name);
}