#include<stdio.h>
int calculate_String_Weight(char *str);
int main()
{
    char str[] = "afgh";
    printf("String Weight: %d ", calculate_String_Weight(str));;
    return 0;
}
int calculate_String_Weight(char* str)
{
    int i = 0, sum = 0;
    while (str[i] != '\0')
    {
        sum += str[i];
        i++;
    }
    return sum;
}