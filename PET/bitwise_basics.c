/* #include<stdio.h>
int main()
{
    unsigned int num = 0xFF;
    int i, count = 0;
    for (i = 31;i >= 1;i--)
    {
        if (num & (1 << i))
        {
            count++;
        }
    }
    printf("The Set Bits is %d\n", count);
    return 0;
} */
/* #include<stdio.h>
int main()
{
    unsigned int num = 0x32;
    int i, count = 0;
    for (i = 7;i >= 0;i--)
    {
        if (num & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    unsigned int num = 0x49;
    unsigned int orginal = num;
    num = num | ((1 << 4) - 1);
    printf("Setting bits from LSB :");
    printf("%#x", num);
    num = orginal;
    num = num | ~((1 << 4) - 1);
    printf("Clear bits from LSB :");
    printf("%#x", num);
    num = orginal;
    num = num & ((1 << 4) - 1);
    printf("Get bits from LSB :");
    printf("%#x", num);

} */
 #include<stdio.h>
int main()
{
    unsigned int num = 0x25;
    unsigned int orginal = num;
    int bits = 3;
    int pos = 5;
    num = num | (((1 << bits) - 1) << (pos - bits + 1));
    printf("Setting bits from position %d:", pos);
    printf("%X\n", num);
    num = orginal;
    num = num & ~(((1 << bits) - 1) << (pos - bits + 1));
    printf("Clearing bits from position %d:", pos);
    printf("%X\n", num);
    num = orginal;
    num = (num >> pos - bits + 1) & ((1 << bits) - 1);
    printf("Get bits from position %d:",pos);
    printf("%X\n", num);


}
