#include<stdio.h>
#include<stdlib.h>
void vowel_check(char* str);
int count = 0;
int main()
{
    char str[10];
    printf("Enter the String: ");
    scanf("%s", str);
    vowel_check(str);
    printf("%d", count);
    return 0;
}
void vowel_check(char* str)
{
    int i;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
        i++;
    }
}