#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist* temp1 = *tail1; //pointer to last node of first list
	Dlist* temp2 = *tail2; //pointer to last node of second list
	int result = 0, borrow = 0;
	while (temp1 != NULL || temp2 != NULL) // loop until both lists are fully traversed 
	{
		if (temp1 != NULL && temp2 != NULL) // both numbers still have digits
		{
			result = temp1->data - temp2->data - borrow; // subtract the digits and borrow
			temp1 = temp1->prev; // move left in first number
			temp2 = temp2->prev; // move left in second number
		}
		else if (temp1 != NULL && temp2 == NULL) // only first number has digits left
		{
			result = temp1->data - borrow; // subtract borrow from remaining digit
			temp1 = temp1->prev; // move left in first number
		}
		if (result < 0) //Handle negative result by borrowing from next higher digit
		{
			result = result + 10; // adjust result after borrow
			borrow = 1;  // set borrow for next iteration
		}
		else
		{
			borrow = 0; // no borrow needed
		}
		dl_insert_first(headR, tailR, result); // insert digit at front of result list
	}
	while ((*headR)->data == 0 && (*headR)->next != NULL)  /* Remove leading zeros from the result */
	{
		Dlist* swap = *headR;
		*headR = (*headR)->next;
		(*headR)->prev = NULL;
		free(swap);
	}
	return SUCCESS;
}
