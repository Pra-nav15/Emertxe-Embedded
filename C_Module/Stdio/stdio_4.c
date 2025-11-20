#include <stdio.h>
int main()
{
int ret;
char string[] = "Hello World";
ret = printf("%d",printf("%s\n", string));// Right to Left
printf("The previous printf() printed %d chars\n", ret);
return 0;
}