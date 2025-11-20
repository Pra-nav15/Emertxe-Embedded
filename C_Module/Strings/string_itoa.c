#include<stdio.h>

char* str_itoa(int num,char str[]);

int main()
{
    char str[100];
    int num;
    scanf("%d",&num);
    char* ret=str_itoa(num,str);
    printf("Integer to string is %s",ret);
}

char* str_itoa(int num,char str[])
{
    int i=0, j=0, rem, len=0;
    char temp;
    int flag = 0;
    if(num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if(num < 0) 
    {   
        flag = 1;
        num = -num;
    }
    while(num > 0) 
    {
        rem = num % 10;
        str[i++] = rem + '0';
        num /= 10;
        len++;
    }

    if(flag==1) 
    {
        str[i++] = '-';
        len++;
    }

    str[i] = '\0'; 
    for(j=0; j < len/2; j++) {
        temp = str[j];
        str[j] = str[len-1-j];
        str[len-1-j] = temp;
    }

    return str;
}
