#include <stdio.h>
int main() {
    // Fixed size — can't be changed at runtime
    int matrix[3][4];
    printf("Fully Static Matrix (3x4):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = i + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}