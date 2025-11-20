#include <stdio.h>

int main()
{
    int num;
    FILE *fptr;
    char ch, target;
    int count = 0;

    fptr = fopen("check.txt", "r");
    if (fptr == NULL)
    {
        printf("File does not exist\n");
        return 0;
    }

    fseek(fptr, 0, SEEK_END);
    num = ftell(fptr);
    rewind(fptr);
    printf("Total no of characters in file is %d\n", num);
    printf("Enter the character to count: ");
    scanf(" %c", &target);

    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch == target)
        {
            count++;
        }
    }

    printf("Character '%c' occurred %d times in the file.\n", target, count);
    fclose(fptr);
    return 0;
}
