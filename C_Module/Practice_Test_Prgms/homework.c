#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    int* arr = malloc(8*sizeof(int));
    printf("Enter the Character : ");
    scanf("%c", &ch);
    for (int i = 7; i >= 0; i--)
    {
        if (ch & (1 << i))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    for (int i = 7;i >= 0;i--)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}