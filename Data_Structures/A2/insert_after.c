#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    Slist* temp = malloc(sizeof(Slist));
    temp = *head;
    while (temp != NULL)
    {
        if (g_data == temp->data)
        {
            Slist* new = malloc(sizeof(Slist));
            if (new == NULL)
            {
                printf("Memory Allocation Failed");
                return FAILURE;
            }
            new->data = n_data;
            new->link = temp->link;
            temp->link = new;
            return SUCCESS;
        }
        else
        {
            temp = temp->link;
        }
    }
    return FAILURE;
}