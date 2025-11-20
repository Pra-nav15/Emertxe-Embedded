#include<stdio.h>
int main(){
    int i,j,count=1,num;
    char ch;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=num;j>=i;j--)  // to print inverted right triangle shape   // for(j=1;j<=i;j++) to print right triangle shape
        {
            printf("%c ",ch+90);  // A-Z means 65 to 90
            ch--;// value descending // ch++ value ascending
        }
        printf("\n");
    }
    return 0;
}