#include<stdio.h>
#include<string.h>
void sort_occurences(int size,int* arr);
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    sort_occurences(n, arr);
    return 0;
}
void sort_occurences(int size,int* arr)
{
    int flag;
    for (int i = 0;i < size;i++)
    {
        flag = 0;
        for (int j = 0;j < i;j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            int occurences = 1;
            for (int k = i + 1;k < size;k++)
            {
                if (arr[i] == arr[k])
                {
                    occurences++;
                }
            }
            
        }
    }

}