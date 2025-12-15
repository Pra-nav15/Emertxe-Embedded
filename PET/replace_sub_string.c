#include<stdio.h>
#include<string.h>
void replace_sub_string(char* str1,char* str2);
int main()
{
    char str1[100] = "Bye Everyone";
    char str2[100] = "Welcome all";
    replace_sub_string(str1, str2);
    return 0;
}
void replace_sub_string(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char str[len1];
    int k = 0;
    for (int i = 0;i < len2;i++)
    {
        if (str2[i] == ' ')
        {
            break;
        }
        str[k++] = str2[i];
    }
    str[k] = '\0';
    int j = 0;
    for (int i = 0;i < len1;i++)
    {
        if (str1[i] == ' ')
        {
            break;
        }
        str1[i] = str[j++];
    }
    printf("%s\n", str1);


}