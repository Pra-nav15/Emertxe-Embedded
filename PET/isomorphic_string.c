#include<stdio.h>
#include<string.h>
void is_isomorphic(char* str1,char* str2);
int main()
{
    char str1[100], str2[100];
    printf("Enter the String 1:");
    scanf("%[^\n]", str1);
    printf("Enter the String 2:");
    scanf(" %[^\n]", str2);
    is_isomorphic(str1, str2);
    return 0;
}
void is_isomorphic(char* str1, char* str2)
{
    int flag=0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0;i < len1;i++)
    {
        for (int j = i + 1;j < len2;j++)
        {
            if ((str2[i] != str2[j] && str1[i] == str1[j] ) || (str1[i] != str1[j] && str2[i] == str2[j]))
            {
                printf("Not Isomorphic Strings\n");
                return;
            }
        }
    }
    printf("Isomorphic Strings\n");
    return;
}