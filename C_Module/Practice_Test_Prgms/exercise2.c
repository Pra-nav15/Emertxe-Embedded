#include<stdio.h>
int main(){
    int n,count=1;
    printf("Enter the number count: ");
    scanf("%d",&n);
    while(count<=n)
    {
        printf("%d ",count);
        count++;
    }
    printf("\n");
    return 0;
}