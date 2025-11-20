#include <stdio.h>

void demoFunction() {
    printf("Inside function: %s\n", __func__);  // Name of current function
}

int main() {
    printf("File name   : %s\n", __FILE__);     // Current file name
    printf("Compilation : %s\n", __DATE__);    // Compilation date
    printf("Time        : %s\n", __TIME__);    // Compilation time
    printf("Line number : %d\n", __LINE__);    // Current line number
    demoFunction();                             
    return 0;
}
