#include "sll.h"

int sl_delete_list(Slist **head)
{
    Slist* next = NULL;
    if (head == NULL)
    {
        return FAILURE;
    }
    else
    {
        Slist* temp = *head;
        while (temp != NULL)
        {
            *head = temp->link;
            free(temp);
            temp = *head;
        }
        return SUCCESS;
    }
}