/*#include<stdio.h>
int main()
{
    int num1;
    int num2  =sizeof(num1 = 1 + 2 + 3);
    printf("num1 is %lu and num2 is %lu\n",num1,num2);
    return 0;
}
    */
/* #include <stdio.h>

int main()
{
	int iter = 0;

	while(iter < 10)
	{
		if (iter == 5)
		{
			continue;
		}
		
        printf("%d \n", iter);
		iter++;
	}

	return 0;
} */
#include<stdio.h>
#include <unistd.h>
int main()
{
	int i,count=0;
	for(i=0;i<100;i++)
	{
	   printf("-");
	   fflush(stdout);
	   sleep(2);
	}
}