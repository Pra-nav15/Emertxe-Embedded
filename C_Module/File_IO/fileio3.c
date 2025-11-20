#include<stdio.h>
int main()
{
    FILE *fp=fopen("Students.txt","w+");
    if(fp==NULL)
    {
        printf("File Not Exist");
        return 0;
    }
    int rollno=137;
    char name[]="Pranav Prasad";
    float marks=95.56;
    int temp;
    fprintf(fp,"%d %s %g",rollno,name,marks);
    rewind(fp); // brings file pointer back to beginning 
    fscanf(fp,"%d",&temp);
    printf("%d\n",temp);
    fclose(fp);

}
