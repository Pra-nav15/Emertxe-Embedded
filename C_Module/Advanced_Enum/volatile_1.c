#include<stdio.h>
/*The Volatile keyword prevents the compiler from performing optimizations on code involving volatile objects
,thus ensuring that each volatile variable assignment and read has a corresponding memory access*/
int main()
{
    //long int wait; // Try without and with volatile qualifier
    volatile long int wait; //Try without and with volatile qualifier
    unsigned char bit = 0;

    while(1)
    {
        bit = !bit;
        printf("The bit is now : %d\r", bit);
        fflush(stdout);
        for (wait = 0xFFFFFFF;wait--;); // delay loop
    }
    return 0;
}