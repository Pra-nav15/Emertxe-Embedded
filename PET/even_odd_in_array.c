#include<stdio.h>
int main()
{
    int size = 5;
    int arr[5] = { 4,1,5,3,8 };
    printf("Even elements : ");
    for (int i = 0;i < size;i++)
    {
        if (arr[i] % 2 == 0 && arr[i] != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\nOdd elements : ");
    for (int i = 0;i < size;i++)
    {
        if (arr[i] % 2 != 0 && arr[i] != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    for (int i = 0;i < size;i++)
    {
          if (arr[i] == 0)
          {
            printf("\n0 is neither Odd or Even\n");
          }
      }
}