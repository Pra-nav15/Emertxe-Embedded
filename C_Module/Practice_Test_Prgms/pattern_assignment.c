/*#include <stdio.h>
int main() {
    int a,b,result;
    printf("Enter number to get table *  times: ");
    scanf("%d %d",&a,&b);
    for(int i=1;i<=b;++i)
    {
        result=i*a;
        printf("%d * %d  = %d\n",i,a,result);
    }
*/
/* #include<stdio.h>
int main()
{
    int i,j,num;
    printf("Enter the value of n: ");
    scanf("%d",&num);
    for(i=num;i>=1;i--)
    {
        for(j=i;j<=num;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    for(i=2;i<=num;i++)
    {
        for(j=i;j<=num;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
} */
/* #include<stdio.h>
int main()
{
    int i,j,num;
    printf("Enter the value of n: ");
    scanf("%d",&num); 
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(i==1 && j==1 && j==num ||  i==num && j==1 && j==num || i==1 || i==num)
              printf("*");
            else if(i==j || i+j-1==num)
             printf("*");
            else
             printf(" ");
        }
        printf("\n");
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,num;
    printf("Enter the value of n: ");
    scanf("%d",&num); 
    for(i=num;i>=1;i--)
    {
        for(j=i;j>=num;j--)
        {
         printf("*");
        }
        printf("\n");
    }
    return 0;
} */

#include<stdio.h>
int main()
{
    int num,i,j;
    printf("Enter the value of n: ");
    scanf("%d",&num);
    for(i=num;i>=1;i--)
    {
        for(j=i;j>=1;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}