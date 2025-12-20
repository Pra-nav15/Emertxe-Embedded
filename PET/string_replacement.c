#include<stdio.h>
#include<string.h>
void string_replacement(char* str1, char* str2, int len1, int len2);
int main()
{
    char str1[100], str2[100];
    printf("Enter The  String1 :");
    scanf("%[^\n]", str1);
    printf("Enter The  String2 :");
    scanf(" %[^\n]", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    string_replacement(str1, str2, len1, len2);
    //printf("%s", str1);
    return 0;
}
void string_replacement(char* str1, char* str2, int len1, int len2)
{
    int index_1 = 0,index_2 = 0;
    for (int i = 0;i < len1;i++)
    {
        if (str1[i] == ' ')
        {
            index_1 = i - 1;
            break;
        }
    }
    for (int i = 0;i < len2;i++)
    {
        if (str2[i] == ' ')
        {
            index_2 = i - 1;
            break;
        }
    }
    int k = 0;
    char result[100];
    for (int i = 0;i < index_1+1;i++)
    {
        result[k++] = str1[i];
    }
    for (int i = index_2+1;i < len2;i++)
    {
        result[k++] = str2[i];
    }
    result[k] = '\0';
    printf("%s\n", result);

}