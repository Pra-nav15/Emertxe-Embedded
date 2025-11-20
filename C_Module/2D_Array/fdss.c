#include <stdio.h> //First Dynamic(Row) Second Static(column)
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns (fixed for each row): ");
    scanf("%d", &cols);

    int (*matrix)[cols];  // Pointer to array of 'cols' ints
    matrix = (int (*)[cols])malloc(rows * sizeof(int[cols]));
    // Allocate memory for a 2D array with 'rows' number of rows and 'cols' columns.
    // Each row is treated as a fixed-size array of 'cols' integers.
    // The cast (int (*)[cols]) tells the compiler: "this is a pointer to an array of 'cols' ints".
    // This lets us use matrix[i][j] syntax just like a normal 2D array.

    printf("Dynamic Rows, Static Columns:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}