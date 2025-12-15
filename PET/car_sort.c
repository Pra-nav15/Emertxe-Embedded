#include<stdio.h>
#include<stdlib.h>
typedef struct Cars
{
    char Brand[100];
    char Model[100];
    int year;
}Car;

int main()
{
    int num;
    printf("Enter the number of cars: ");
    scanf("%d", &num);
    Car* s = malloc(num * sizeof(Car));
    for (int i = 0;i < num;i++)
    {
        printf("Enter details of Car %d\n", i + 1);
        printf("Brand : ");
        scanf("%s", s[i].Brand);
        printf("Model : ");
        scanf("%s", s[i].Model);
        printf("Brand : ");
        scanf("%d", &s[i].year);
    }
    for (int i = 0;i < num;i++)
    {
        for (int j = i + 1;j < num;j++)
        {
            if (s[i].year > s[j].year)
            {
                Car temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("Sorted Cars according to Date of Mf Year : \n");
    for (int i = 0;i < num;i++)
    {
        printf("Brand: %s, ", s[i].Brand);
        printf("Model: %s, ", s[i].Model);
        printf("Year: %d ", s[i].year);
        printf("\n");
    }
}