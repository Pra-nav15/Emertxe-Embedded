#include<stdio.h>
int main(){
    int num,i=1;
    printf("Enter the numbers: ");
    scanf("%d",&num);
    while(i<=num)
    {
        if(i%2!=0)
        {
           printf("%d ",i);
        }
        i++;
    }
    printf("\n");
    return 0;
}