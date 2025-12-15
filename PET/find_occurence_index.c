#include<stdio.h>
#include<string.h>
void find_occurrence_index(char* pattern, char* text);
int main()
{
    char text[] = "batmanandrobinarebat";
    char pattern[] = "bat";
    find_occurrence_index(pattern, text);
    return 0;
}
void find_occurrence_index(char* pattern, char* text)
{
    int len1 = strlen(pattern);
    int len2 = strlen(text);
    int result[50];
    int p = 0;
    for (int i = 0; i < len2; i++)
    {
        int k = i;
        int count = 0;
        for (int j = 0; j < len1; j++)
        {
            if (pattern[j] == text[k])
            {
                count++;
                k++;
            }
            else
            {
                break;
            }
        }
        if (count == len1)
        {
            result[p++] = i;
        }
    }
    for (int i = 0; i < p; i++)
    {
        printf("%d ", result[i]);
    }
}
