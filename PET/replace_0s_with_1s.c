#include<stdio.h>
int replace_0s_with_1s(int num);
int main()
{
    int num = 609080240;
    int ret = replace_0s_with_1s(num);
    printf("%d", ret);
    return 0;
}
int replace_0s_with_1s(int num)
{
    int orginal = num;
    int replaced = 0;
    while (orginal != 0)
    {
        if (orginal % 10 == 0)
        {
            replaced = replaced * 10 + 1;
        }
        else
        {
            replaced = replaced * 10 + (orginal % 10);
        }
        orginal /= 10;
    }
    int rev = 0, rem = 0;
    while (replaced != 0)
    {
        rem = replaced % 10;
        rev = rev * 10 + rem;
        replaced /= 10;
    }
    return rev;

}