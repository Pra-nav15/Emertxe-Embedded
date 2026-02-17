#include<stdio.h>
char* words[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
"twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine",
"thirty", "thirty one", "thirty two", "thirty three", "thirty four", "thirty five", "thirty six", "thirty seven", "thirty eight", "thirty nine",
"forty", "forty one", "forty two", "forty three", "forty four", "forty five", "forty six", "forty seven", "forty eight", "forty nine",
"fifty", "fifty one", "fifty two", "fifty three", "fifty four", "fifty five", "fifty six", "fifty seven", "fifty eight", "fifty nine" };
int main()
{
    int hh, mm;
    printf("Enter Hours (0-23) and Minutes (0-59): ");
    if (scanf("%d %d", &hh, &mm) != 2)
    {
        printf("There should be 2 parameters");
        return 0;
    }
    if (hh < 0 || hh>23 || mm < 0 || mm>59)
    {
        printf("Invalid Time");
        return 0;
    }
    int hour12 = hh % 12;
    if (hour12 == 0)
    {
        hour12 = 12;
    }
    if (mm == 0)
    {
        printf("%s o'clock", words[hour12]);
        if (hh == 0)
        {
            printf(" Midnight");
        }
        else if (hh==12)
        {
            printf(" Noon");
        }
        printf("\n");
    }
    else
    {
        printf("%s %s\n", words[hour12], words[mm]);
    }
    return 0;
}