#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // For example, input 8

    int half = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // TOP-LEFT X (i: 0-3, j: 0-3)
            if (i < half && j < half && (i == j || i + j == half - 1)) {
                printf("* ");
            }

            // TOP-RIGHT X (i: 0-3, j: 4-7)
            else if (i < half && j >= half && (i == j - half || i + j == n - 1)) {
                printf("* ");
            }

            // BOTTOM-LEFT X (i: 4-7, j: 0-3)
            else if (i >= half && j < half && (i - half == j || i + j == n - 1)) {
                printf("* ");
            }

            // BOTTOM-RIGHT X (i: 4-7, j: 4-7)
            else if (i >= half && j >= half && (i - half == j - half || i + j == n + half - 1)) {
                printf("* ");
            }

            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
