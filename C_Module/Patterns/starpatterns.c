/*#include<stdio.h>
int main()
{
    int num,i,j,k;
    printf("Enter the value of n: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(k=num;k>=i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
*/
/* #include<stdio.h>
int main()
{
    int num,i,j,k;
    printf("Enter the value of n: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(k=num;k>=i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=num-1;i>=1;i--)
    {
        for(k=1;k<=num-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++)
        {
            printf(" *");
        }
        printf("\n");
    }
    return 0;
} */
