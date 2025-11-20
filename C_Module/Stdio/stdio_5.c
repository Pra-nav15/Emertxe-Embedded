#include <stdio.h>

int main() {
    int x = 10;
    char buffer[50];
    FILE *fp;

    // printf -> purpose: print formatted output to console (stdout)
    printf("Value of x = %d\n", x);

    // fprintf -> purpose: print or  formatted output to a file or stream
    fp = fopen("output.txt", "w");
    fprintf(fp, "Value of x = %d\n", x);
    fclose(fp);

    // sprintf -> purpose: print or store formatted output into a string (character array)
    sprintf(buffer, "Value of x = %d", x);
    printf("%s\n", buffer);

    return 0;
}
