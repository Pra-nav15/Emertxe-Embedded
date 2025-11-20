#include <stdio.h>

int main() {
    int x = 10;        // normal variable
    int *p;            // pointer to int
    p = &x;            // p stores address of x

    printf("Value of x = %d\n", x);
    printf("Address of x = %p\n", &x);
    printf("Pointer p stores = %p\n", p);
    printf("Value pointed by p = %d\n", *p); // dereferencing

    *p = 20;  // change value of x using pointer
    printf("New value of x = %d\n", x);

    return 0;
}
