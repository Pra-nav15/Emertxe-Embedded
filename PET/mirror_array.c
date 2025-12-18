#include<stdio.h>
void  mirror_array(int* arr1,int* arr2,int s1,int s2);
int main()
{
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    if (s1 != s2)
    {
        printf("Cannot Check Mirro Array \n");
    }
    else
    {
        int arr1[s1], arr2[s2];
        printf("Array 1 Elements : \n");
        for (int i = 0;i < s1;i++)
        {
            scanf("%d", &arr1[i]);
        }
        printf("Array 2 Elements : \n");
        for (int i = 0;i < s2;i++)
        {
            scanf("%d", &arr2[i]);
        }
        mirror_array(arr1, arr2, s1, s2);
        return 0;
    }
}
void  mirror_array(int* arr1, int* arr2, int s1, int s2)
{
    int count = 0;
    for (int i = 0;i < s1;i++)
    {
        if (arr1[s1-i-1] == arr2[i])
        {
            count++;
        }
    }
    printf("%d", count);
    if (count == s1)
    {
        printf("Mirror Arrays\n");
    }
    else
    {
        printf("Not Mirror Arrays\n");
    }
}