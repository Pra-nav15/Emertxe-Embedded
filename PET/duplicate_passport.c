#include <stdio.h>
#include <string.h>

void remove_duplicate_passports(char passport_ids[][20], int n);

int main()
{
    int n;
    scanf("%d", &n);
    char passport_ids[n][20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", passport_ids[i]);
    }
    remove_duplicate_passports(passport_ids, n);
    return 0;
}

void remove_duplicate_passports(char passport_ids[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag= 0;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(passport_ids[i], passport_ids[j]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag==0)
        {
            printf("%s ", passport_ids[i]);
        }
    }
}
