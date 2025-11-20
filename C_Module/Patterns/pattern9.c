#include<stdio.h>
int main(){
    int i,j,num,k;
    scanf("%d",&num);
    for(i=1;i<=num;i++) //pyramid
    {
        for(k=num-1;k>=i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++)
        {
            printf("*");

        }
        printf("\n");
    }
    for(i=1;i<num;i++)   //inverted pyramid
    {
        for(k=1;k<=2*i;k++)
        {
            printf(" ");
        }
        for(j=num;j>=(2*i-1);j--)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}