//Padding//


/* #include<stdio.h>
int main()
{
    char ch1;
    int i;
    char ch2;
    int j;
    short s;
    //smart compilers optimise the declaration ---> data alignment
    printf("Addr of ch1=%p\n",&ch1);
    printf("Addr of i=%p\n",&i);
    printf("Addr of ch2=%p\n",&ch2);
    printf("Addr of j=%p\n",&j);
    printf("Addr of s=%p\n",&s);
    return 0;
} */
#include <stdio.h>

struct test
{
    char ch1;   // 1 byte
    int i;      // 4 bytes (likely aligned at 4-byte boundary)
    char ch2;   // 1 byte
    int j;      // 4 bytes
    short s;    // 2 bytes (aligned at 2-byte boundary)
};

int main()
{
    struct test t;

    printf("Addr of ch1 = %p\n", (void*)&t.ch1);
    printf("Addr of i   = %p\n", (void*)&t.i);
    printf("Addr of ch2 = %p\n", (void*)&t.ch2);
    printf("Addr of j   = %p\n", (void*)&t.j);
    printf("Addr of s   = %p\n", (void*)&t.s);

    printf("Size of struct test = %zu\n", sizeof(struct test));

    return 0;
}
