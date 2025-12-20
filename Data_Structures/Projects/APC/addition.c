#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	Dlist* temp1 = *tail1; //pointer to last node of first list
	Dlist* temp2 = *tail2; //pointer to last node of second list
	int result = 0, carry=0;
	while (temp1 != NULL || temp2 != NULL) // loop until both lists are fully traversed 
	{
		if (temp1 != NULL && temp2 != NULL) // both numbers still have digits
		{
			result = temp1->data + temp2->data + carry; // add digits and carry
			temp1 = temp1->prev; // move left in first number
		    temp2 = temp2->prev; // move left in second number
		}
		else if (temp1 != NULL && temp2 == NULL) // only first number has digits left
		{
			result = temp1->data + carry; // add digit plus carry
			temp1 = temp1->prev; // move left in first number
		}
		else if (temp1 == NULL && temp2 != NULL) // only second number has digits left
		{
			result = temp2->data + carry; // add digit plus carry
			temp2 = temp2->prev; // move left in second number
		}
		if (result > 9) // If result sum is more than 9, store last digit and carry over
		{
			dl_insert_first(headR, tailR, (result % 10)); // insert the remainder digit at result list fron
			carry = 1; // carry over to next addition
		}
		else
		{
			dl_insert_first(headR, tailR, result); // insert sum directly at result list front
			carry = 0; // no carry needed
		}
	}
	if (carry == 1)
	{
		dl_insert_first(headR, tailR, carry); //If there’s still a carry after finishing, add it as a new digit 
	} 
	return SUCCESS;
}
