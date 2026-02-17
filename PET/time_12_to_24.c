#include <stdio.h>
#include <string.h>

void railway_time_convert(char *time);

int main()
{
    char time[100];
    printf("Enter the Time : ");
    scanf("%s", time);
    railway_time_convert(time);
    return 0;
}
void railway_time_convert(char *time)
{
    int len = strlen(time);
    if (time[len - 2] == 'P' || time[len - 2] == 'p')
    {
        if (time[0] == '0' || time[0] == '1')
        {
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            if (hour != 12)
            {
                hour += 12;
                time[0] = (hour / 10) + '0';
                time[1] = (hour % 10) + '0';
            }
        }
    }
    else if (time[len - 2] == 'A' || time[len - 2] == 'a')
    {
        if (time[0] == '1' && time[1] == '2')
        {
            time[0] = '0';
            time[1] = '0';
        }
    }
    time[len - 2] = '\0';
    printf("%s\n", time);
}
