#include<stdio.h>
int main()
{
    int month;
    int year;
    int leap_year;
    printf("Enter The Month and Year :");
    scanf("%d %d", &month, &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        leap_year = 1;
    }
    else
    {
        leap_year = 0;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        printf("The Number of days in the month %d is 31",month);
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        printf("The Number of days in the month %d is 30",month);
    }
    else if (month == 2)
    {
       
        if (leap_year)
        {
            printf("The Number of days in the month %d will be 29", month);
        }
        else
        {
            printf("The Number of days in the month %d will be 28", month);
        }
    }
    else
    {
        printf("%d is Invalid Month", month);
    }
}