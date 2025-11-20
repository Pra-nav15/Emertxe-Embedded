#include<stdio.h>
int main(){
    int i,j,num,count=15;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d  ",count);
            count--;// for descending order of number     // count++ for normal ascending order
        }
        printf("\n");
    }
    return 0;
}