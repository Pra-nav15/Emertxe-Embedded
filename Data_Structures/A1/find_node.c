#include "sll.h"

int find_node(Slist *head, data_t key)
{
    int count = 0;
    if (head == NULL)
    {
        return FAILURE;
    }
    else
    {
        count++;
        while (head != NULL)
        {
            if (head->data == key)
            {
                return count;
            }
            else
            {
                count++;
                head = head->link;
            }
        }
        return DATA_NOT_FOUND;
    }
}
