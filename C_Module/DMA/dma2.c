#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr = (int*)malloc(4);
    ptr[0] = 5;
    int* ptr2 = realloc(ptr, 8);
    if (ptr2 != ptr)
    {
        ptr = ptr2;
    }
    ptr[1] = 10;
    printf("%d %d\n", ptr[0], ptr[1]);
    free(ptr);
    return 0;
}