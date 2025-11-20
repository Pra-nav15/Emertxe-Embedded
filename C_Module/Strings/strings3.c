
#include <stdio.h>

int main() {
    int a = 100, b = 125;

    // 1. Pointer to const int
    const int *ptr1 = &a;
    // *ptr1 = 200;   //  Not allowed (cannot modify value)
    ptr1 = &b;        //  Allowed (can change address)
    printf("ptr1 points to %d\n", *ptr1);

    // 2. Const pointer to int
    int *const ptr2 = &a;
    *ptr2 = 200;      //  Allowed (can change value)
    // ptr2 = &b;     //  Not allowed (cannot change address)
    printf("ptr2 points to %d\n", *ptr2);

    // 3. Const pointer to const int
    const int *const ptr3 = &a;
    // *ptr3 = 300;   //  Not allowed (cannot modify value)
    // ptr3 = &b;     //  Not allowed (cannot change address)
    printf("ptr3 points to %d\n", *ptr3);

    return 0;
}
