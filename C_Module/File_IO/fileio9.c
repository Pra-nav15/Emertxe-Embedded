#include<stdio.h>
int main()
{
    FILE *fptr;
    char ch;
    int count = 1;
    fptr = fopen("test.txt", "r");
    if(fptr==NULL)
    {
        printf("File Not exist");
        return 0;
    }
    while((ch=getc(fptr)) !=EOF)
    {
         if(ch=='\n')
         {
            count++;
         }
    }
    printf("Total Lines are %d", count);
}