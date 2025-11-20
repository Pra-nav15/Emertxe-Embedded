#include <stdio.h>
#include <string.h>  

enum Weekdays {
    sunday = 1,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

int main()
{
    char today[10];
    printf("Enter the Day: ");
    scanf("%s", today);  
    if (strcmp(today, "sunday") == 0)
    {
        printf("This is %d day in Week\n", sunday);
    }
    else if (strcmp(today, "monday") == 0)
    {
        printf("This is %d day in Week\n", monday);
    }
    else if (strcmp(today, "tuesday") == 0)
    {
        printf("This is %d day in Week\n", tuesday);
    }
    else if (strcmp(today, "wednesday") == 0)
    {
        printf("This is %d day in Week\n", wednesday);
    }
    else if (strcmp(today, "thursday") == 0)
    {
        printf("This is %d day in Week\n", thursday);
    }
    else if (strcmp(today, "friday") == 0)
    {
        printf("This is %d day in Week\n", friday);
    }
    else if (strcmp(today, "saturday") == 0)
    {
        printf("This is %d day in Week\n", saturday);
    }
    else
    {
        printf("Invalid Day\n");
    }
    return 0;
}