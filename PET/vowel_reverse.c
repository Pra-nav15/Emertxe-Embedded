#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void vowels_reverse(char* str, int len);
int main()
{
    char str[100];
    scanf("%[^\n]", str);
    int len = strlen(str);
    vowels_reverse(str,len);
    return 0;
}
void vowels_reverse(char* str, int len)
{
    int* index_arr = (int*)calloc(len, sizeof(int));
    int k = 0;
    for (int i = 0;i < len;i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            index_arr[k++] = i;
        }
    }
    int start = 0, end = k - 1;
    while (start < end)
    {
        char temp = str[index_arr[start]];
        str[index_arr[start]] = str[index_arr[end]];
        str[index_arr[end]] = temp;
        start++;
        end--;
    }
    printf("%s", str);
}