#include<stdio.h>
void print_array(int size,int* ptr);
int main()
{
    int size=5;
    int arr[5]={10,20,30,40,50};
    print_array(size,arr);
}
void print_array(int size,int* ptr)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("Index %d has element %d\n",i,*ptr++);
    }
}