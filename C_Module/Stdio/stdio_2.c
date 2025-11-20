#include <stdio.h>

int main()
{
    // %c : character
    printf("%%c : %c\n", 'A');

    // %d, %i : integer (decimal)
    printf("%%d %%i : %d %i\n", 10, 10);

    // %o : octal
    printf("%%o : %o\n", 8);

    // %x, %X : hexadecimal (lowercase, uppercase)
    printf("%%x %%X %%x : %x %X %x\n", 0xA, 0xA, 10);

    // %u : unsigned decimal integer
    printf("%%u : %u\n", 255);

    // %f, %F : floating-point (decimal notation)
    printf("%%f %%F : %f %F\n", 2.0, 2.0);

    // %e, %E : scientific notation (exponential form)
    printf("%%e %%E : %e %E\n", 1.2, 1.2);

    // %a, %A : hexadecimal floating-point notation
    printf("%%a : %a\n", 123.4);

    // %g, %G : shortest representation (%f or %e)
    printf("%%g %%G : %g %G\n", 1.21, 1.0);

    // %s : string
    printf("%%s : %s\n", "Hello");

    return 0;
}
