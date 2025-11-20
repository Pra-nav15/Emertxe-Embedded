/* #include<stdio.h>
int main(){
    int i,j,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<num;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}*/
/*#include<stdio.h>
int main(){
    int i,j,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
    */
/*#include<stdio.h>
int main(){
    int i,j,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(i==1 || i==num || j==1 || j==num)
             printf("*");
            else
             printf(" ");
             
        }
        printf("\n");
    }
    return 0;
}
    */
/*#include<stdio.h>
int main(){
    int i,j,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(i==3 || j==3)
             printf("*");
            else
             printf(" ");
             
        }
        printf("\n");
    }
    return 0;
}
*/
#include<stdio.h>
int main(){
    int i,j;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            if(i==1 || i==5 || i==3)
            {
                printf("* ");
            }
            else if(i==2 && j==1 || i==4 && j==5)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
             
        }
        printf("\n");
    }
    return 0;
}