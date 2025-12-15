#include "apc.h"

int dl_delete_list(Dlist** head, Dlist** tail)
{
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }
    else
    {
        Dlist* temp;
        while (*head != NULL)
        {
            temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
}