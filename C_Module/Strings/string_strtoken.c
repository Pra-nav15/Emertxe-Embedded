#include <stdio.h>
#include <string.h>   // needed for strtok

int main()
{
    char str[] = "My name is Pranav Prasad";
    char del[] = " ";
    char *ptr;

    puts(str);

    ptr = strtok(str, del);
    while(ptr != NULL)
    {
        puts(ptr);    // ✅ print token, not full string
        ptr = strtok(NULL, del);
    }

    return 0;
}

