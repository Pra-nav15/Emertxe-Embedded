/* #include<stdio.h>
int main()
{
     int i,j,num,k;
     printf("Enter the number for the pyramid: ");
     scanf("%d",&num);
     for(i=1;i<=num;i++)
     {
        for(k=num;k>=1;k--)
        {
            printf("  ");
        }
        for(j=num;j>=1;j++)
        {
            printf("* ");
        }
        printf("\n");
     }
} */
/* #include<stdio.h>
int main()
{
     int i,j,num,k;
     //printf("Enter the number for the pyramid: ");
     scanf("%d",&num);
     for(i=1;i<=num;i++)
     {
        for(j=num;j>=1;j++)
        {
            if(i<=j)
             printf("* ");
            else
             printf(" "); 
        }
        printf("\n");
     }
} */
/* #include<stdio.h>
int main()
{
    int n,m,x;
    //printf("Enter n : ");
    scanf("%d",&n);
    //printf("Enter m : ");
    scanf("%d",&m);
    x=(n-m)/2;
    if(n%2!=0 && m%2!=0)
    {
        for(int i=1;i<=x;i++)
        {
            printf("$");
        }
        for(int j=1;j<=m;j++)
        {
            printf("*");
        }
        for(int k=1;k<=x;k++)
        {
            printf("$");
        }
    }
    else
    {
        printf("Numbers are odd");
    }
    return 0;
    
} */
/* #include<stdio.h>
int main()
{
    int rem,num,count=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while(num>0)
    {
       rem=num%10;
       count+=rem;
       num=num/10;
    }
    printf("%d ",count);
    return 0;
} */
/* #include <stdio.h>

int main() {
    int i, j, size, count;

    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements: ");
    for(i = 0; i < size; i++) {
        count = 0;
        for(j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                count= 1;
                break;
            }
        }
        if(count== 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
 */
#include <stdio.h>

int main() {
    int i, j, size, k=0,count=0;

    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size],uniq_arr[size];

    printf("Enter array elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements: ");
    for(i = 0; i < size; i++) 
    {
        count = 0;
        for(j = 0; j < size; j++) {
            if(arr[j] == arr[j+1]) 
            {
                count= 1;
            }
        }
        if(count==0) 
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}