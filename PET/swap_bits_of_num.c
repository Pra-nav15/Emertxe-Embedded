#include<stdio.h>
int main()
{
    unsigned int num = 10;
    int n, m;
    scanf("%d %d", &n, &m);
    int bit1, bit2;
    bit1 = (num >> n) & 1;
    bit2 = (num >> m) & 1;
    if (bit1 != bit2)
    {
        num = num ^ (1 << n);
        num = num ^ (1 << m);
    }
    printf("%#X", num);
}