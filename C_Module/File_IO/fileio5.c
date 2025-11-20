#include<stdio.h>
int main()
{
    FILE *fptr;
    int num1,num2,num3,num4;
    num1=35;
    num2=45;
    fptr=fopen("file1.txt","w+");
    if(fptr==NULL)
    {
        printf("Error\n");
        return 0;
    }
    fwrite(&num1,sizeof(num1),1,fptr);
    fwrite(&num2,sizeof(num2),1,fptr);
   
    printf("num1=%d num2= %d\n",num1,num2);
    rewind(fptr);

    fread(&num3,sizeof(num1),1,fptr);
    fread(&num4,sizeof(num2),1,fptr);

    printf("num3=%d num4= %d",num3,num4);

    fclose(fptr);

    return 0;

}