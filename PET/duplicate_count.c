#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 1, 2, 1,4};
    int n = 6;
    int flag = 0, count;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    break;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}
