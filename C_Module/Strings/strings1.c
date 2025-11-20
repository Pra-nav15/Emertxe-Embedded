/* #include<stdio.h>
int main()
{
    char str[10];//buffer size;
    scanf("%s",str); // only takes Hello if we read Hello World does not take after space
    printf("%s",str);
} */
/* #include<stdio.h>
int main()
{
    char str[10];//buffer size;
    gets(str); // shows error illegal
    printf("%s",str);
} */

/* #include<stdio.h>
int main()
{
    char str[10];//buffer size;
    fgets(str,10,stdin); // using fgets
    printf("%s",str);
} */
#include<stdio.h>
int main()
{
    char str[6];//buffer size;
    scanf("%5[^\n]",str); // using selected scanf
    printf("%s",str);
}




/* 1. Using scanf

This stops at the first whitespace (space, tab, newline).

So input like Hello World → only "Hello" is stored.

2. Using gets(str)

gets() was removed from the C11 standard because it’s unsafe (no buffer-size check → buffer overflow possible).

Modern compilers warn or error when you use it.

3. Using fgets
fgets(str, 10, stdin);

Safe way → takes input including spaces, up to size-1 chars, and appends \0.

If newline \n fits inside the buffer, it’s also stored.
Example: input Hello → "Hello\n\0".

You might want to strip the \n.

4. Using selected scanf
scanf("%[^\n]", str);


This tells scanf → “read everything until newline \n”.

Unlike %s, it allows spaces.

But ⚠ no buffer size check! → if input exceeds char str[6], it causes buffer overflow.

👉 You should use a field width with %[...] to stay safe:

scanf("%5[^\n]", str); // reads up to 5 chars + '\0' 
*/