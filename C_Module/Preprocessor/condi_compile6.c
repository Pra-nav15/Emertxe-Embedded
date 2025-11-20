#include<stdio.h>
#include<stdlib.h>

#if defined (STATIC) || defined (DYNAMIC)
#define SIZE 100
#   else



int main()
{
#if defined STATIC
    char buffer[SIZE];
#elif defined DYNAMIC
    char* buffer = malloc(SIZE * sizeof(char));
#endif

#if defined (STATIC) || defined (DYNAMIC)
    fgets(buffer, SIZE, stdin);
    printf("%s\n", buffer);
#endif
    
}

