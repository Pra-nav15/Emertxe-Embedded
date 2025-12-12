#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist* temp1 = *tail1;
	Dlist* temp2 = *tail2;
	int result = 0, borrow = 0;
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1 != NULL && temp2 != NULL)
		{
			if(temp1->data > temp2->data)
			{
				result = temp1->data - temp2->data - borrow;
				borrow = 0;
			}
			else if(temp1->data < temp2->data)
			{
				temp1->data = temp1->data + 10;
				result = temp1->data - temp2->data - borrow;
				borrow = 1;
			}
			dl_insert_first(headR, tailR, result);
			temp1 = temp1->prev;
		    temp2 = temp2->prev;
		}
		else if (temp1 != NULL && temp2 == NULL)
		{
			result = temp1->data - borrow;
			dl_insert_first(headR, tailR, result);
			temp1 = temp1->prev;
		}
	}
	return SUCCESS;
}
