#include<stdio.h>
int main()
{
    unsigned int num;
    int pos;
    int n;
    printf("Enter a number :");
    scanf("%u", &num);
    printf("Enter position (0 to 31) :");
    scanf("%u", &pos);
    printf("Enter number of bits to extract :");
    scanf("%u", &n);

    unsigned int result = (num >> (pos - n + 1)) & ((1 << n) - 1);

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d", (result >> i) & 1);
    }
    printf("\n");

}