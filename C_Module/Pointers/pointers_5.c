#include <stdio.h>

int main() {
    unsigned int num = 0x12345678;
    unsigned char *p = (unsigned char*)&num;

    printf("Memory Representation:\n");
    for (int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: %02X\n", i, *(p+i));
    }

    if (*p == 0x78) {
        printf("Little Endian System\n");
    } else {
        printf("Big Endian System\n");
    }

    return 0;
}
