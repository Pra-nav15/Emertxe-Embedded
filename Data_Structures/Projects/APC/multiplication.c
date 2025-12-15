#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist* headR1 = NULL;
	Dlist* tailR1 = NULL;
	Dlist* headR2 = NULL;
	Dlist* tailR2 = NULL;
	Dlist* temp1 = NULL;
	Dlist* temp2 = *tail2;
	int carry = 0, result = 0, count = 0;
    *headR = NULL;
    *tailR = NULL;
    while (temp2 != NULL)
    {
		carry = 0;
		temp1 = *tail1;
		for (int i = 0; i < count; i++)
        {
            dl_insert_first(&headR1, &tailR1, 0);
        }
        while (temp1 != NULL)
        {
            result = (temp1->data * temp2->data) + carry;
            carry = result / 10;
            result = result % 10;
            dl_insert_first(&headR1, &tailR1, result);
            temp1 = temp1->prev;
        }
        if (carry > 0)
        {
            dl_insert_first(&headR1, &tailR1, carry);
        }
        if (headR2 == NULL)
        {
            headR2 = headR1;
            tailR2 = tailR1;
        }
        else
        {
            addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);
            dl_delete_list(&headR1, &tailR1);
            dl_delete_list(&headR2, &tailR2);
            headR2 = *headR;
            tailR2 = *tailR;
            *headR = NULL;
            *tailR = NULL;
        }
        headR1 = NULL;
        tailR1 = NULL;
        count++;
        temp2 = temp2->prev;
    }
    *headR = headR2;
    *tailR = tailR2;
    return SUCCESS;
}
