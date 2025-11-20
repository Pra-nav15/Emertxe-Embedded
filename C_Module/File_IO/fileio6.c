#include<stdio.h>
struct Data
{
    int num1;
    char oper;
    int num2;
    char str[10];
    float num3;
};
int main()
{
    struct Data d1={2,'-',10,"Pranav",2.25};
    struct Data d2;// first it will be garbage values
    printf("%d %c %d %s %f\n",d2.num1,d2.oper,d2.num2,d2.str,d2.num3);
    FILE *fptr;
    fptr=fopen("file2.txt","w+");
    if(fptr==NULL)
    {
        printf("Error\n");
        return 0;
    }
    fwrite(&d1,sizeof(d1),1,fptr); // write the data of structure to the file
    rewind(fptr); // set the offset to beginning
    fread(&d2,sizeof(d1),1,fptr); // read to the new memory location of d2 (copy d1 from file to d2)

    printf("Copied Values from d1\n");
    printf(" %d %c %d %s %f",d2.num1,d2.oper,d2.num2,d2.str,d2.num3);
    fclose(fptr);

    return 0;

}