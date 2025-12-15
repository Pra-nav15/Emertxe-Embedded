#include<stdio.h>
#include<string.h>
void time_convert(char* str);
int main()
{
    char str[100];
    scanf("%s", str);
    time_convert(str);
    return 0;
}
void time_convert(char* str)
{
    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    if(str[len - 2] == 'P')
    {
        if (str[0] == '0' && str[1] > 0)
        {
            str[0] = '1';
            int num;
            num = str[1] - 48;
            if (num < 9)
            {
                str[1] = str[1] + (num);
            }
            else
            {
                str[1] = '0';
            }
        }
        int k = 0;
        while (k < len - 2)
        {
            printf("%c", str[k]);
            k++;
        }
    }
    else if (str[len - 2] == 'A')
    {
        int j = 0;
        while (j < len - 2)
        {
            printf("%c", str[j]);
            j++;
        }
    }
    else
    {
        printf("Invalid Format");
        return;
    }
}