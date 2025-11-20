#include<stdio.h>
int main()
{
    char ch;
    FILE *fp=fopen("test.txt","r");
    if(fp==NULL)
    {
        printf("File doesn't exist\n");
        return 1;
    }
    printf("Index is %ld\n",ftell(fp));
    while(ch=fgetc(fp))
    {
        if(feof(fp))// to check end of file
         break;
        fputc(ch,stdout);
    }
    printf("\nTotal Count of Characters: %ld",ftell(fp));
    printf("\n");
    fclose(fp);
    return 0;
}
