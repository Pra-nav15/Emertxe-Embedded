#include<stdio.h>
void sq_cu(int num1,int* square, int* cube);
int main()
{
    int num1,square=0,cube=0;
    printf("Enter the number : ");
    scanf("%d",&num1);
    sq_cu(num1,&square,&cube);
    printf("Square is %d\nCube is %d",square,cube);
}
void sq_cu(int num1,int* square, int* cube)
{
    *square=(num1)*(num1);
    *cube=(num1)*(num1)*(num1);
}