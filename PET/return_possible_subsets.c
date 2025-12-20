#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    int total = 1 << n;   // 2^n subsets
    for (int i = 0; i < total; i++)
    {
        printf("[");
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                printf("%d ", arr[j]);
            }
        }
        printf("]\n");
    }
    return 0;
}
