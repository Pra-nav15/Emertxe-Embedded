#include<stdio.h>
#if 1
//prints the string
#define MACRO(STR) #STR
int main()
{
    printf(MACRO(Hello));
    printf(MACRO(Hello));
    printf("\n");
    return 0;
}
#endif
