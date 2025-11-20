#include <stdio.h>
int main() {
    int num, pos;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position to CLEAR (starting from 0): ");
    scanf("%d", &pos);
    num = num & ~(1 << pos);
    printf("Number after clearing bit %d = %d\n", pos, num);
    return 0;
}
