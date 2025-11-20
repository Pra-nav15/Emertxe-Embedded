#include<stdio.h>
union Test
{
    char option;
    int id;
    double height;
};
int main()
{
    union Test temp_var;
    temp_var.height = 7.2;
    temp_var.id = 0x1234;
    temp_var.option = '1';
    printf(" %c %d %g", temp_var.option, temp_var.id, temp_var.height);
    //printf(" %p %p %p", temp_var.option, temp_var.id, temp_var.height);
    return 0;
}