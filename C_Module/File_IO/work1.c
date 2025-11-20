#include<stdio.h>
#include<string.h>
struct Student{
    char name[20];
    float p;
    float c;
    float m;
};
int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    float psum = 0, csum = 0, msum = 0;
    struct Student s[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the name %d: ", i + 1);
        //__fpurge(stdin);
        scanf(" %[^\n]", s[i].name);
        printf("Enter P C M Marks :");
        scanf("%f %f %f", &s[i].p, &s[i].c, &s[i].m);
        psum += s[i].p;
        csum += s[i].c;
        msum += s[i].m;
    }
    float p_avg = psum / size;
    float c_avg = csum / size;
    float m_avg = msum / size;
    
    FILE *fptr = fopen("binary.out", "wb");
    if(fptr==NULL)
    {
        printf("Error in opening file\n");
        return 0;
    }
    fwrite(&size, sizeof(int), 1, fptr);
    fwrite(s, sizeof(struct Student), size, fptr);
    fwrite(&p_avg, sizeof(float), 1, fptr);
    fwrite(&c_avg, sizeof(float), 1, fptr);
    fwrite(&m_avg, sizeof(float), 1, fptr);

    fclose(fptr);
    printf("Stored Successfully in the binary.out file\n");

    const char *strline = "---------------------------------------------------------";
    printf("%-25s %18s %18s %18s\n", "Name", "Physics Marks", "Chemistry Marks", "Maths Marks");
    printf("%s\n", strline);
    for (int i = 0; i < size;i++)
    {
        printf("%-25s %10g %10g %10g\n", s[i].name, s[i].p, s[i].c, s[i].m);
    }
    printf("%s\n", strline);
    printf("%-25s %10g %10g %10g\n", "Average",p_avg,c_avg,m_avg);
    printf("%s\n", strline);

    return 0;
}