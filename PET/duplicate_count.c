#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 1, 2, 1, 4};
    int n = 6;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int flag = 0;
        for(int k = 0; k < i; k++)
        {
            if(arr[i] == arr[k])
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            int c = 0;
            for(int j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    c++;
                }
            }
            if(c > 0)
            {
                printf("%d occurs %d times\n", arr[i], c + 1);
                count++;
            }
        }
    }

    printf("Total numbers with duplicates: %d\n", count);
    return 0;
}
