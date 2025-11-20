/*
Name:Pranav Prasad
Date:18/07/2025
Description:Program to generate AP,GP,HP Series
Sample Input:Enter the First Number 'A':
             Enter the Common Difference / Ratio 'R':
             Enter the number of terms 'N':
Sample Output:AP = 2, 5, 8, 11, 14
              GP = 2, 6, 18, 54, 162
              HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428
*/
#include<stdio.h>
int main()
{
    int a,r,n,gp,hp;
    printf("Enter the First Number 'A': ");
    scanf("%d",&a);
    gp=a;
    hp=a;
    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d",&r);
    printf("Enter the number of terms 'N':  ");
    scanf("%d",&n);
    if(n>=1)
    {
        for(int i=1;i<=n;i++)
        {
           printf("%d, ",a);
           a=a+r;
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
           printf("%d, ",gp);
           gp=gp*r;
        }
        printf("\n");
        a=hp;
        for(int i=1;i<=n;i++)
        {
           float h=(float)1/a;
           printf("%f, ",h);
           a=a+r;
        }
        printf("\n");
    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}