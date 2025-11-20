#include <stdio.h>
int main()
{
int num1 = 123;
char ch = 'A';
float num2 = 12.345;
char string1[] = "sprintf() Test";
char string2[100];
sprintf(string2, "%d %c %f %s\n",num1 , ch, num2, string1); // stores in buffer instead of display to stdout i.e stores num1 ch num2 string1 to the string2
printf("%s", string2);
return 0;
}
/*+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+
| 1 | 2 | 3 |   | A |   | 1 | 2 | . | 3 | 4 | 5 | 0 | 0 | 0 |   | s | p | r | i | n | t | f | ( | ) |   | T | e | s | t | \0 |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30
*/
