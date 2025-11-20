/* #include<stdio.h>
void swap(void*, void*, int);
int main()
{
    int a =0x13579, b =0x02468;
    swap(&a, &b, sizeof(int));
    printf("After Swap a = %x and b = %x\n", a, b);
    return 0;
}
void swap(void *a, void *b, int size)
{
    char temp;
    for (int i = 0;i < size;i++)
    {
        temp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = temp;
    }
    return;
} */
#include<stdio.h>
void swap(void*, void*, int);
int main()
{
    int a =0x13579, b =0x02468;
    swap(&a, &b, sizeof(int));
    printf("After Swap a = %x and b = %x\n", a, b);
    return 0;
}
void swap(void *a, void *b, int size)
{
    for (int i = 0;i < size;i++)
    {
        *((char*)a + i) = *((char*)a + i) ^ *((char*)b + i);
        *((char*)b + i) = *((char*)a + i) ^ *((char*)b + i);
        *((char*)a + i) = *((char*)a + i) ^ *((char*)b + i);
    }
    return;
}