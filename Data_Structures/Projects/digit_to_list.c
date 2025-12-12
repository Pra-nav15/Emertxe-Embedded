#include "apc.h"

void digit_to_list(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, char* argv[])
{
    char* str1 = argv[1];
    char* str2 = argv[3];
    int i = 0;
    while (str1[i] != '\0')
    {
        int data1 = 0;
        data1 = str1[i] - '0';
        dl_insert_last(head1, tail1, data1);
        i++;
    }
    int j = 0;
    while (str2[j] != '\0')
    {
        int data2 = 0;
        data2 = str2[j] - '0';
        dl_insert_last(head2, tail2, data2);
        j++;
    }
}