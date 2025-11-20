#include<stdio.h>
struct Student{
    char name[20];
    float p;
    float c;
    float m;
};
int main()
{
    FILE *fptr = fopen("binary.out", "rb");
    if(fptr==NULL)
    {
        printf("Error in opening file\n");
        return 0;
    }
    int size;
    if(fread(&size,4,1,fptr)==0)
    {
        printf("Error in reading No of Students\n");
        return 0;
    }
    struct Student s[size];
    for (int i = 0; i < size;i++)
    {
        if(fread(&s[i],sizeof(struct Student),1,fptr)==0)
        {
            printf("Error in reading details of students\n");
            return 0;
        }
    }
    float p_avg = 0, c_avg = 0, m_avg = 0;
    if(fread(&p_avg,4,1,fptr)==0)
    {
        printf("Error in reading Average of Physics\n");
        return 0;
    }
    if(fread(&c_avg,4,1,fptr)==0)
    {
        printf("Error in reading Average of Chemistry\n");
        return 0;
    }
    if(fread(&m_avg,4,1,fptr)==0)
    {
        printf("Error in reading Average of Maths\n");
        return 0;
    }
    fclose(fptr);
    const char *strline = "---------------------------------------------------------";
    printf("%-5s %13s %15s %12s\n", "Name", "Physics Marks", "Chemistry Marks", "Maths Marks");
    printf("%s\n", strline);
    for (int i = 0; i < size;i++)
    {
        printf("%-5s %13g %15g %12g\n", s[i].name, s[i].p, s[i].c, s[i].m);
    }
    printf("%s\n", strline);
    printf("%-5s %13g %15g %12g\n", "Average",p_avg,c_avg,m_avg);
    printf("%s\n", strline);
}