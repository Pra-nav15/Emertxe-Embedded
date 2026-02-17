#include <stdio.h>

int main() {
    int i, j, space, rows;
    char ch;

    rows = 4;
    for (i = 1; i <= rows; i++)
    {
        for (int k= 1; k <= k- i; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            ch = 'A' + j - 1;
            printf("%c", ch);
        }
        for (j = i - 1; j >= 1; j--)
        {
            ch = 'A' + j - 1;
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
