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
    /* while((ch=fgetc(fp))!=EOF)
         fputc(ch,stdout);
    */
    while(ch=fgetc(fp))
    {
        if(feof(fp))
         break;
        fputc(ch,stdout);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
