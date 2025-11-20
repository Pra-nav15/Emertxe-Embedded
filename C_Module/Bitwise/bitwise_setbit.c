#include <stdio.h>
int main() {
    int num, pos;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position to SET (starting from 0): ");
    scanf("%d", &pos);
    num = num | (1 << pos);
    printf("Number after setting bit %d = %d\n", pos, num);
    return 0;
}
