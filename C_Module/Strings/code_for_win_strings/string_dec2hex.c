#include <stdio.h>

char* dec_to_hex(int num, char str[]);

int main()
{
    int num;
    char str[100];

    printf("Enter decimal number: ");
    scanf("%d", &num);

    char* hex_str = dec_to_hex(num, str);
    printf("Decimal number %d is converted to hexadecimal string %s\n", num, hex_str);

    return 0;
}

char* dec_to_hex(int num, char str[])
{
    int i = 0, rem;
    char temp;
    
    while(num > 0)
    {
        rem = num % 16;
        if(rem < 10)
            str[i++] = rem + '0'; 
        else
            str[i++] = (rem-10) + 'A';
        num /= 16;
    }
    str[i] = '\0';

    for(int j = 0; j < i/2; j++)
    {
        temp = str[j];
        str[j] = str[i-1-j];
        str[i-1-j] = temp;
    }

    return str;
}
