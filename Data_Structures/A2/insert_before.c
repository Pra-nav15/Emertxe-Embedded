#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    Slist* temp = malloc(sizeof(Slist));
    temp = *head;
    Slist* prev = temp;
    prev = NULL;
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
            new->link = temp;
            prev->link = new;
            return SUCCESS;
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
    return FAILURE;
}