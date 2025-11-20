/* #include<stdio.h>
int main()
{
    int num;
    char ch='A';
    scanf("%d", &num);
    for(int i=1;i<=num;i++)
    {
        for (int j = 1;j <= i;j++)
        {
            printf("%c ",ch++);
        }
        printf("\n");
    }
} */
/* #include<stdio.h>
int main()
{
  int num;
  char ch = 'A';
  int count = 1;
  scanf("%d", &num);
  for(int i=0;i<=num;i++)
  {
    int k,j;
    for(k=0;k<=2*num-i;k++)
    {
      printf(" ");
    }
    for(j=0;j<=2*i;j++)
    {
        //printf("%c",j+65);
        //printf("*");
        printf("%d ", count);
        count++;
    }
    printf("\n");
  }
} */
#include<stdio.h>
int main()
{
  int num;
  char ch = 'A';
  int count = 1;
  scanf("%d", &num);
  for(int i=0;i<=num;i++)
  {
    int k,j;
    for(k=0;k<=num-i;k++)
    {
      printf(" ");
    }
    for(j=0;j<=i;j++)
    {
        printf("%d ", count);
        count++;
    }
    printf("\n");
  }
  for(int i=num;i>=0;i--)
  {
    int k,j;
    for(k=0;k<=num-i;k++)
    {
      printf(" ");
    }
    for(j=0;j<=i;j++)
    {
        printf("%d ", count);
        count++;
    }
    printf("\n");
  }
}
