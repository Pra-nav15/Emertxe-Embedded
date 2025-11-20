#include<stdio.h>
int main(int argc, char **argv)
{
    printf("Total Argument Count is %d", argc);
    printf("List of Arguments:\n");
    for (int i = 0;i< argc;i++)
    {
        printf("Argument[%d] is %s\n", i, argv[i]);
    }
    return 0;
}
