#include<stdio.h>
int main(){
    int i,j,num,count=1;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(int k=1;k<=num-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
             printf("%d ",count);
             count=(i+j)/(j+1);
        }
        printf("\n");
    }
    return 0;
}