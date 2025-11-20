#include <stdio.h>

int str_itoa(char* str);

int main()
{
    char str[100];
    scanf("%s", str);
    str_itoa(str);
    return 0;
}

int str_itoa(char* str)
{
    int i = 0, rem = 0, sum = 0;
    int flag = 1;   // default positive

    // case: invalid like "--12" or "++34"
    if((str[0] == '-' || str[0] == '+') && (str[1] == '-' || str[1] == '+'))
    {
        printf("String is zero\n");
    }

    // sign check
    if(str[0] == '-')
    {
        flag = -1;
        i++;
    }
    else if(str[0] == '+')
    {
        flag = 1;
        i++;
    }

    // conversion loop
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            rem = str[i] - 48;        // convert char to digit
            sum = sum * 10 + rem;      // build number
        }
        else
        {
            flag=0;
            break;
        }
        i++;
    }
    if(flag==0)
    {
        printf("String is zero\n");
    }
    sum = sum * flag;   // apply sign
    printf("%d\n", sum);
    return sum;
}
