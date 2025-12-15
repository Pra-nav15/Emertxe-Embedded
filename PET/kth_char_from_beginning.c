#include<stdio.h>
#include<string.h>
void kth_character(char* str, int k);
int main()
{
    int k;
    char str[100];
    printf("Enter the String: ");
    scanf("%[^\n]", str);
    printf("Enter the Value of k: ");
    scanf("%d", &k);
    kth_character(str, k);
    return 0;
}
void kth_character(char* str, int k)
{
    int len = strlen(str);
    if (k == 0)
    {
        printf("Invalid Value of k");
        return;
    }
    printf("Every %dth character  from the beginning: ",k);
    for (int i = 0;i < len;i++)
    {
        if (i == k)
        {
            printf(" %c",str[i-1]);
            k = k * 2;
        }
    }
}