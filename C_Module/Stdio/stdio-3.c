#include<stdio.h>
int main()
{
    printf("%3d %3d\n", 1, 1);
    printf("%3d %3d\n", 10, 10);
    printf("%3d %3d\n", 100, 100);

    printf("%10s\n", "Hello");
    printf("%20s\n", "Hello");

    printf("%*d\n", 1, 1); //* means take width from argument before the value.
    printf("%*d\n", 2, 1);
    printf("%*d\n", 3, 1);


    printf("%3.2d\n",1);
    printf("%12.8s\n","Hello World"); // total spaces----->fills 12 spaces fills 8 spaces only but Hello world has more than 8 charcters only print upto 8 characters
}