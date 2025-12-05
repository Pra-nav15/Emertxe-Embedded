#include "sll.h"

int sl_delete_last(Slist **head)
{
    if (head == NULL)
    {
        return FAILURE;
    }
    else
    {
        Slist* temp = *head;
        Slist* prev = NULL;
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
    }
}