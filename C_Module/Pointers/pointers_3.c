#include <stdio.h>

int main() {
    int arr[3] = {5, 10, 15};
    int *p = arr;

    for (int i = 0; i < 3; i++) {
        printf("arr[%d] = %d, *(p+%d) = %d\n", i, arr[i], i, *(p+i));
    }

    return 0;
}
