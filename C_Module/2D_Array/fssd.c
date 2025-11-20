#include <stdio.h> // First (Row) Second Dynamic(column)
#include <stdlib.h>

int main() {
    int *matrix[100];  // Max 100 rows statically
    int rows, cols;

    printf("Enter number of rows (max 100): ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Static Rows, Dynamic Columns:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    return 0;
}