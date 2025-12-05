#include "sll.h"

int sl_delete_first(Slist **head)
{
    if (head == NULL)
    {
        return FAILURE;
    }
    else
    {
        Slist* temp = *head;
        *head = temp->link;
        free(temp);
    }
}