#include <stdio.h>
int main() {
    int num, pos, bit;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position to GET (starting from 0): ");
    scanf("%d", &pos);
    bit = (num >> pos) & 1;
    printf("Bit at position %d = %d\n", pos, bit);
    return 0;
}
