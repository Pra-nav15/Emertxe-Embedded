#include<stdio.h>
void square(int num);
void cube(int num);
void display(void (*funptr)(int));
void square(int num)
{
    printf("Square is %d\n",num*num);
}
void cube(int num)
{
   printf("Cube is %d\n", num*num*num);
}
void display(void (*funptr)(int))
{
    funptr(5);
}
int main()
{
    display(square);
    display(cube);
    return 0;
}