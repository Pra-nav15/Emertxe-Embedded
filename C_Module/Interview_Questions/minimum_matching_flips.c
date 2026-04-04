#include<stdio.h>
int bit_compare(int result, int k);
int main()
{
    int n, k, result = 0;
    printf("Size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Array elements :");
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Target: ");
    scanf("%d", &k);
    for (int i = 0;i < n-1;i++)
    {
        result += (arr[i] ^ arr[i + 1]);
    }
    int count = 0;
    for (int i = 31;i >= 0;i--)
    {
        if ((result ^ k) & (1 << i))
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}