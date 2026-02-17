#include <stdio.h>
#include <string.h>

void longest_palindromic_sub_string(char *str);
int main()
{
    char str[100];
    printf("Enter the String : ");
    scanf(" %[^\n]", str);
    longest_palindromic_sub_string(str);
    return 0;
}
void longest_palindromic_sub_string(char *str)
{
    int len = strlen(str);
    int maxLen = 1, start = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            int l = i, r = j;
            int flag = 1;

            while(l < r)
            {
                if(str[l] != str[r])
                {
                    flag = 0;
                    break;
                }
                l++;
                r--;
            }
            if(flag && (j - i + 1) > maxLen)
            {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    printf("Longest Palindromic Substring: ");
    for(int i = start; i < start + maxLen; i++)
        printf("%c", str[i]);
}
