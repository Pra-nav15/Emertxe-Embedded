#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    Slist* temp = malloc(sizeof(Slist));
    temp = *head;
    Slist* prev = temp;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            prev->link = temp->link;
            free(temp);
        }
        else
        {
            Slist* prev = NULL;
            temp = temp->link;
        }
    }
}