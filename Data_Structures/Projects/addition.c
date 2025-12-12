#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	Dlist* temp1 = *tail1;
	Dlist* temp2 = *tail2;
	int result = 0, carry=0;
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1 != NULL && temp2 != NULL)
		{
			result = temp1->data + temp2->data + carry;
			temp1 = temp1->prev;
		    temp2 = temp2->prev;
		}
		else if (temp1 != NULL && temp2 == NULL)
		{
			result = temp1->data + carry;
			temp1 = temp1->prev;
		}
		else if (temp1 == NULL && temp2 != NULL)
		{
			result = temp2->data + carry;
			temp2 = temp2->prev;
		}
		if (result > 9)
		{
			dl_insert_first(headR, tailR, (result % 10));
			carry = 1;
		}
		else
		{
			dl_insert_first(headR, tailR, result);
			carry = 0;
		}
	}
	if (carry == 1)
	{
		dl_insert_first(headR, tailR, carry);
	}
	return SUCCESS;
}
