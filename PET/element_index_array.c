#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void element_index_search(char* str[], char x);
int main()
{
    char *str[] = { "leet","code" };
    char x = 'e';
    element_index_search(str, x);
    return 0;
}
void element_index_search(char* str[], char x)
{
    int len1 = strlen(str[0]);
    int len2 = strlen(str[1]);
    for (int i = 0;i < len1;i++)
    {
        if (str[0][i] == x)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 0;i < len2;i++)
    {
        if (str[1][i] == x)
        {
            printf("%d ", i);
        }
    }
}