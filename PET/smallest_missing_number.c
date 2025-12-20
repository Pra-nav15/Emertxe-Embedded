#include<stdio.h>
int main()
{
    int arr[5];
    for (int i = 0;i < 5;i++)
    {
        scanf("%d", &arr[i]);
    }
    int smallest = 1, flag = 0;
    while (1)
    {
        for (int i = 0;i < 5;i++)
        {
            flag = 0;
            if (arr[i] == smallest)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("Missing number is %d\n", smallest);
            break;
        }
        smallest++;
    }
}