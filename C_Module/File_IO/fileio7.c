#include<stdio.h>
int main()
{
    FILE *fptr1,*fptr2;
    char ch;

    fptr1=fopen("check.txt","r");
    if(fptr1==NULL)
    {
        printf("Error\n");
        return 0;
    }
    fptr2=fopen("check_copy.txt","w");
    if(fptr2==NULL)
    {
        printf("Error\n");
        return 0;
    }

    while((ch= fgetc(fptr1)) != EOF)
    {
        fputc(ch,fptr2);
    }
    printf("Copied Successfully");
    fclose(fptr1);
    fclose(fptr2);
    return 0;


}