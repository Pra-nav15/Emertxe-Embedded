#include<stdio.h>
int main(){
    int num,count=1,i,j;
    printf("Enter the number: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
      for(j=1;j<=i;i++)
      {
        printf("*",j);
      }
      printf("\n");
    }
    return 0;
}