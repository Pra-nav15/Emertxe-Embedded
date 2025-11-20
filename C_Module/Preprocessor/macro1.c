#include<stdio.h>
#if 1
#define ADD(x,y) x+y
int main()
{
    int a = 100, b = 250;
    printf("Sum is %d\n", 2 * ADD(10, 20)); //---> here it follows precedence so first 2 *10 (since * has high precedence than + and then add 20 so o/p is 40
    // 2 * 10+20 ,so better put paranthesis 2 *(10+20)
    printf("Sum is %d\n", ADD(a, b));
    return 0;
}
#endif

