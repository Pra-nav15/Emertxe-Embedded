#include<stdio.h>
int square(int num);
int cube(int num);
int square(int num)
{
    return num * num;
}
int cube(int num)
{
    return num * num * num;
}
int main()
{
    int num1 = 5, result1, result2;
    int (*squareptr)(int num1) = square;
    result1 = (*squareptr)(num1);
    printf("Square is %d\n", result1);
    int (*cubeptr)(int num1) = cube;
    result2 = (*cubeptr)(num1);
    printf("Cube is %d", result2);
    return 0;
}