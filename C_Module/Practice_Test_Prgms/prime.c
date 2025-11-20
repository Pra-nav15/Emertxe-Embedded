/* #include <stdio.h>

int main() {
    int n, i, j, count;

    printf("Enter the upper limit: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++) {
        count = 0;  // Reset count for each number

        // Count how many times i is divisible
        for(j = 1; j <= i; j++) {
            if(i % j == 0)
                count++;
        }

        // Prime numbers have exactly two divisors: 1 and itself
        if(count == 2)
            printf("%d ", i);
    }

    return 0;
}
 */
/* #include <stdio.h>

int main() {
    int n, i, j, count;

    printf("Enter upto value: ");
    scanf("%d", &n);
    for(i = 2; i <= n; i++) {
        count = 0;  
        for(j = 1; j <= i; j++) {
            if(i % j == 0)
                count++;
        }
        if(count == 2)
            result=i;
    }
    for(i=1;i<=num;i++)
    {
        prin
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    do
    {
       printf("%d ",i);
       i++;
    } while (i<=n);
} */
#include <stdio.h>
int main() {
    int n=0, i, j,count=0;
    printf("Enter upto value:");
    scanf("%d",&n);
    for(i = 2; count < n; i++) { 
        int prime=0;
        for(j = 2; j < i; j++) {
            if(i % j == 0)
            {
              prime=1;
              break;
            }
         }
          if(prime==0)
            {
                printf("%d ",i);
                count++;
            }
        }
        return 0;
}
