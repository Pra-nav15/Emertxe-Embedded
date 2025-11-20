#include <stdio.h>
#include<stdlib.h>

void magic_square(int **ptr, int n);

int main()
{
    int num;
    //printf("Enter a number: ");
    scanf("%d",&num);
    if(num%2!=0 && num!=0)
    {
        int **ptr;
        ptr=(int**)calloc(num,sizeof(int*));
        for(int i=0;i<num;i++)
        {
            ptr[i]=(int*)calloc(num,sizeof(int));
        }
        magic_square(ptr,num);
    }
    else
    {
        printf("Error : Please enter only positive odd numbers");
        return 0;
    }
}
void magic_square(int **ptr, int n)
{
   int i=0,j=n/2;
   int num=1;
   
   while(num<=n*n)
   {
       int row = i, col = j;
       ptr[i][j] = num++;
       i--;
       j++;
       if (i < 0)
       {
           i = n - 1;
       }
       if (j > (n - 1))
       {
           j = 0;
       }
       if (ptr[i][j] != 0)
       {
           i = row + 1;
           j = col;
       }
   }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
          printf("%d ",ptr[i][j]);
      }
      printf("\n");
   }
}