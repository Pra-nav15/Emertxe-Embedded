#include <stdio.h>

int main() {
    int x = 42;
    int *p = &x;   // pointer to int
    int **pp = &p; // pointer to pointer

    printf("Value of x = %d\n", x);
    printf("Value via single pointer *p = %d\n", *p);
    printf("Value via double pointer **pp = %d\n", **pp);

    **pp = 100; // change value of x using double pointer
    printf("New value of x = %d\n", x);

    return 0;
}
