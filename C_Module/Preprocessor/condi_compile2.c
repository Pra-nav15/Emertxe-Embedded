/* #ifndef MACRO
Controlled Text 
#endif */
#include <stdio.h>
#undef METHOD1
#define METHOD1
int main()
{
    #ifndef METHOD1 //condn is true - 1
        puts("Hello World");
    #else // if not defined
        printf("Pranav");
    #endif
        return 0;
}