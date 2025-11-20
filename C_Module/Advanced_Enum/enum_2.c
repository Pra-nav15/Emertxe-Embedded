#include<stdio.h>
typedef enum
{
    e_red= 1 , //default value is 0 then increment sequentially from next line
    e_blue = 4,
    e_green, // so e_green should be 5 since sequential
    e_black,
    // e_black, ----> not allowed cannot declare twice in same scope 
}Color;
int main()
{
    //can be declared in diffrent scope
    Color e_white = 6, e_black, e_pink; // contains garbage values
    printf("white = %d\n", e_white); // 6
    //e_black and e_pink should be 6 and 7 but it is declared in main scope so it will have gv.
    printf("black = %d\n", e_black);
    printf("pink = %d\n", e_pink);

    printf("green = %d\n", e_green);//5
    printf("red = %d\n", e_red);//1
    printf("blue = %d\n", e_blue);//4
    return 0;
}