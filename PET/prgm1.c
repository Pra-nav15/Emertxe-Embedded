#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printNonRepeatingCharacters(char* str);
int main()
{
    char str[100];
    scanf("%[^\n]",str);
    printNonRepeatingCharacters(str);
}
void printNonRepeatingCharacters(char* str)
{
    int len = strlen(str);
    char result[len+1];
    int count, k = 0;
    for (int i = 0;i < len;i++)
    {
        count = 0;
        for (int j = 0;j < len;j++)
        {
            if (str[i] == str[j] && i!=j)
            {
                count++;
            }
        }
        if (count == 0)
        {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';
    printf("%s", result);
}