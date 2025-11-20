#include<stdio.h>
int main(){
int num;
char count='A';
printf("Enter max lines: ");
scanf("%d",&num);
for(int i=1;i<=num;i++)
{
    for(int j=1;j<=i;j++)
    {
        printf("%c ", count);
        count++;
        
    }
    printf("\n");
}
}
