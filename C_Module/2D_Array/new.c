#include <stdio.h>
#include <stdlib.h>

void add_elements(void *);
void remove_elements(void *, int);
void display_elements(void *, int);

char has_c1 = 0, has_c2 = 0;
int has_short = 0, has_int = 0;
float has_float = 0;
double has_double = 0;

int main()
{
    void *ptr = malloc(8);
    int choice, index = 0;

    while (1)
    {
        printf("\nMenu :\n");
        printf("1. Add element\n2. Remove element\n3. Display element\n4. Exit\n");
        printf("Choice --> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_elements(ptr);
            break;
        case 2:
            remove_elements(ptr, index);
            break;
        case 3:
            display_elements(ptr, index);
            break;
        case 4:
            free(ptr);
            return 0;
        default:
            printf("Invalid Option\n");
        }
    }
}

void add_elements(void *ptr)
{
    int option;
    printf("Enter the type you have to insert:\n");
    printf("1. char\n2. short\n3. int\n4. float\n5. double\n");
    printf("Choice ---> ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        if (has_c1 == 0 && has_double == 0)
        {
            printf("Enter char: ");
            scanf(" %c", (char *)ptr);
            has_c1 = 1;
        }
        else if (has_c2 == 0 && has_double == 0)
        {
            printf("Enter next char: ");
            scanf(" %c", (char *)ptr + 1);
            has_c2 = 1;
        }
        else
            printf("Char slots full or double already present.\n");
        break;

    case 2:
        if (has_short == 0 && has_double == 0)
        {
            printf("Enter short: ");
            scanf("%hd", (short *)ptr);
            has_short = 1;
        }
        break;

    case 3:
        if (has_int == 0 && has_double == 0)
        {
            printf("Enter int: ");
            scanf("%d", (int *)ptr);
            has_int = 1;
        }
        break;

    case 4:
        if (has_float == 0 && has_double == 0)
        {
            printf("Enter float: ");
            scanf("%f", (float *)ptr);
            has_float = 1;
        }
        break;

    case 5:
        if (has_c1 == 0 && has_c2 == 0 && has_short == 0 && has_int == 0 && has_float == 0)
        {
            printf("Enter double: ");
            scanf("%lf", (double *)ptr);
            has_double = 1;
        }
        break;

    default:
        printf("Invalid type\n");
    }
}

void remove_elements(void *ptr, int index)
{
    display_elements(ptr, index);
    int in;
    printf("Enter the index value to be deleted : ");
    scanf("%d", &in);
    printf("index %d successfully deleted.\n", in);
}

void display_elements(void *ptr, int index)
{
    printf("----------------------------------\n");
    if (has_c1)
        printf("%d --> %c\n", index++, *((char *)ptr));
    if (has_c2)
        printf("%d --> %c\n", index++, *((char *)ptr + 1));
    if (has_short)
        printf("%d --> %hd\n", index++, *((short *)ptr));
    if (has_int)
        printf("%d --> %d\n", index++, *((int *)ptr));
    if (has_float)
        printf("%d --> %f\n", index++, *((float *)ptr));
    if (has_double)
        printf("%d --> %lf\n", index++, *((double *)ptr));
    printf("----------------------------------\n");
}
