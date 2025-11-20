#include<stdio.h>
int main()
{
    FILE *fptr;
    char ch='s';
    fptr = fopen("check.txt", "w+");
    if(fptr==NULL)
    {
        printf("No file exist");
        return 0;
    }
    fseek(fptr, 0, SEEK_END);
    int n = ftell(fptr);
    printf("Length of file is %d\n", n);
    fseek(fptr, -5, SEEK_END);
    ch = fputc(ch,fptr);
    printf("%c", ch);
    fclose(fptr);
}