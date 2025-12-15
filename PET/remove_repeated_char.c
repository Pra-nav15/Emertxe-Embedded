#include<stdio.h>
#include<string.h>
#include<ctype.h>
void remove_repeated_chars(char* str, int len);
int main()
{
    char str[100];
    scanf("%[^\n]", str);
    int len = strlen(str);
    remove_repeated_chars(str, len);
    return 0;
}
void remove_repeated_chars(char* str, int len)
{
    char ret[len];
    int count, k = 0;
    for (int i = 0;i < len;i++)
    {
        count = 0;
        for (int j = 0;j < len;j++)
        {
            if (tolower(str[i]) == tolower(str[j]) && i!=j)
            {
                count++;
            }
        }
        if (count == 0)
        {
            ret[k++] = str[i];
        }
    }
    ret[k] = '\0';
    printf("%s", ret);

}