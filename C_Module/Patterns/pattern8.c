#include<stdio.h>
int main(){
    int i,j,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=1;i<num;i++)
    {
        for(j=num-1;j>=i;j--) // (num-1) to make *  as 1 2 3 4 5 4 3 2 1 // (num) to make * as 1 2 3 4 5 5 4 3 2 1 
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}