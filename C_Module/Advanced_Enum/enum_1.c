#include<stdio.h>
enum bool
{
    e_false, //default value is 0 then increment sequentially from next line
    e_true,
    e_t
};
int main()
{
    printf("%d\n", e_false);
    printf("%d\n", e_true);
    printf("%d\n", e_t);
    return 0;
}