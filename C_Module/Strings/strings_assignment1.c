#include <stdio.h>

void remove_spaces(char str[]);

int main() {
    char str[100];
    fgets(str, 100, stdin);
    remove_spaces(str);
    printf("%s", str);
    return 0;
}

void remove_spaces(char str[]) {
    int i = 0, j;
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i+1] == ' ') 
        {
            // shift everything left starting from position i
            for (j = i; str[j] != '\0'; j++) 
            {
                str[j] = str[j+1];
            }
            // no need for j-- inside just stay at same i
        } 
        else {
            i++;
        }
    }
}
