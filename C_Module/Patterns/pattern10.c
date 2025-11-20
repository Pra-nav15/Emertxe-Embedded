#include<stdio.h>
int main()
{
    int num,i,j;
    int temp=i;
    printf("Enter the value: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=num;j>=1;j--)
        {
            if(i>j)
            {
                printf("* ");
            }
            else
            {
            printf(" ");
            }
        }
        printf("\n");
    }
    for(i=num;i>=1;i--)
    {
        for(j=num;j>1;j--)
        {
            if(temp>j)
            {
                printf(" *");
            }
            else
            {
            printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}