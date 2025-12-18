#include<stdio.h>
int main()
{
    int num1, num2,num3, lcm, hcf, small;
    scanf("%d %d %d", &num1, &num2,&num3);
    lcm = num1 > num2 ? num1 : num2;
    while (1)
    {
        if (lcm % num1 == 0 && lcm % num2 == 0)
        {
            break;
        }
        lcm++;
    }
    printf("LCM is %d\n", lcm); 
    small = num1 < num2 && num1 < num3 ? num1 : num2 < num1 && num2 < num3 ? num2 : num3 < num1 && num3 < num2 ? num3 : 0;
    for (int i = 1;i <= small;i++)
    {
        if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
        {
            hcf = i;
        }
    }
    printf("HCF is %d", hcf);
    return 0;
}