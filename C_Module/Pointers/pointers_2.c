#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;  // points to arr[0]

    printf("First element = %d\n", *p);
    printf("Second element = %d\n", *(p+1));
    printf("Third element = %d\n", *(p+2));

    printf("Address of arr[0] = %p\n", (p));
    printf("Address of arr[1] = %p\n", (p+1));
    printf("Address of arr[2] = %p\n", (p+2));

    return 0;
}
