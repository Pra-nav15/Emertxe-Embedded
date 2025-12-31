#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    int lsum = 0;
    for (int i = 0; i < size; i++)
    {
        int rsum = total - lsum - arr[i];
        if (lsum == rsum)
        {
            printf("Equilibrium Index is %d\n", i);
            return 0;
        }
        lsum += arr[i];
    }

    printf("No Equilibrium Index Found\n");
    return 0;
}
