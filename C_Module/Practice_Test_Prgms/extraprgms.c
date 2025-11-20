/* #include<stdio.h>
int main()
{
    int num,i,count=0;
    scanf("%d",&num);
    while(num!=0)
    {
       num=num/10;
       count++;
    }
    printf("%d ",count);

} */
/* #include<stdio.h>
int main()
{
    int num,n,i;
    scanf("%d %d",&num,&n);
    printf("Enter a number:");
    printf("Next %d set of numbers after %d is : ",n,num);
    for(i=1;i<=n;i++)
    {
     num++;
     printf("%d ",num);
    }
    return 0;
} */
 /* #include<stdio.h>
int main()
{
    int num=8,n,i=1,x=16,y=1;
    printf("The Series: ");
    for(i=1;i<num;i++)
    {
        if(x>=1)
        {
            printf("%d ",x);
            x=x-5;
        }
        else if(x<1)
        {
            y=y+5;
            printf("%d ",y);
        }
    }
     printf("\n");
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int bin,dec=0,bit,i,base=1,rem=0;
    printf("Enter a binary number bits:");
    scanf("%d",&bit);
    printf("Enter a binary number:");
    scanf("%d",&bin);
    for(i=0;i<bit;i++)
    {
        rem=bin%10;
        dec+=base*rem;
        base=base*2;
        bin=bin/10;
    }
    printf("Equivalent decimal of binary value is %d ",dec);
}  */
/* #include<stdio.h>
int main()
{
    int num, result = 0, i, rem = 0, j, temp;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num; 
    for(i = 1; num != 0; i++)
    {
        rem = num % 10; 
        int power = 1;      
        for(j = 1; j <= 3; j++)  
        {
            power*= rem;
        }
        result += power;
        num = num / 10;
    }
    printf("%d ", result);
    if(result == temp)
    {
        printf("The number is an Armstrong number");
    }
    else
    {
        printf("The number is not an Armstrong number");
    }
    return 0;
}
 */
/* #include<stdio.h>
int main()
{
    int num,i,rem=0,result=0;
    printf("Enter the number: ");
    scanf("%d",&num);
    while(num!=0)
    {
        rem=num%10;
        result+=rem;
        num=num/10;
    }
    printf("Result is %d\n",result);
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int num,last,first,digi,power=1,i,mid;
    printf("Enter the digits in a number: ");
    scanf("%d",&digi);
    for(i=1;i<digi;i++)
    {
        power*=10;
    }
    printf("Enter the number: ");
    scanf("%d",&num);
    first=num/power;
    last=num%10;
    mid=num%power;
    mid=mid/10;
    printf("%d is first & %d is last\n",first,last);
    int result=last*power+mid*10+first;
    printf("%d",result);
    return 0;
} */