#include<stdio.h>
int main(){
    int i,j,num,k;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(k=1;k<=2*i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=num;j++)
        {
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}