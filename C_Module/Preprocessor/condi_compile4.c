#include<stdio.h>
#define METHOD 5

int main()
{
#if METHOD == 1
    puts("Arunraj");
#elif METHOD ==2
    puts("Sebin");
#else
    puts("Pranav");
#endif
    return 0;
}