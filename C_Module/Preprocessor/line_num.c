#include<stdio.h>

int main()
{
#line 100 //you can specify line and file name
    printf("This is from file %s at line %d\n", __FILE__, __LINE__);

    printf("This is from file %s at line %d\n", __FILE__, __LINE__);
    return 0;
}