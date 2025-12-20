#include "apc.h"
//Convert input strings (numbers) into doubly linked lists of digits
void digit_to_list(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, char* argv[])
{
    char* str1 = argv[1]; // store first number 
    char* str2 = argv[3]; // store second number
    int i = 0;
    if (str1[0] == '-')
    {
        i = 1;  // skip minus sign
    }
    while (str1[i] != '\0') //Traverse first string and insert each digit into list1
    {
        int data1 = 0;
        data1 = str1[i] - '0'; // convert character to integer digit
        dl_insert_last(head1, tail1, data1); // add the digit to last of list1
        i++;
    }
    int j = 0;
    if (str2[0] == '-')
    {
        j = 1;  // skip minus sign
    }
    while (str2[j] != '\0') //Traverse second string and insert each digit into list2
    {
        int data2 = 0;
        data2 = str2[j] - '0'; // convert character to integer digit
        dl_insert_last(head2, tail2, data2); // add the digit to last of list2
        j++;
    }
}