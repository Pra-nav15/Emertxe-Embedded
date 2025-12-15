#include<stdio.h>
int length_of_last_word(char* str);
void reverse_string(char* str, int start, int end);
int main()
{
    char str[100];
    scanf("%[^\n]", str);
    int ret = length_of_last_word(str);
    printf("Length of last word is %d\n", ret);
    return 0;
}
int length_of_last_word(char* str)
{
    int len = 0,i=0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    int start = 0, end = len-1;
    reverse_string(str, start, end);
    for (int i = 0;i <= len;i++)
    {
        if (str[i] == ' ' || str[i] =='\0')
        {
            end = i - 1;
            reverse_string(str, start, end);
            start = i + 1;
        }
    }
    printf("Reversed Each Word in string is %s \n", str);
    int k = 0,count=0;
    while (str[k] != '\0')
    {
        if (str[k] == ' ')
        {
            return count;
        }
        count++;
        k++;
    }
    return 0;
}
void reverse_string(char* str, int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}