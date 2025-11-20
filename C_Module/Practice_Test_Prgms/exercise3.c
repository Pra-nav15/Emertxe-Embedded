#include<stdio.h>
int main(){
    int n,count=1;
    printf("Enter the number count: ");
    scanf("%d",&n);
    while(n>=count)
    {
        printf("%d ",n);
        n--;
    }
    printf("\n");
    return 0;
}