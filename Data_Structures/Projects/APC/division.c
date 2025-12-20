#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int count = 0;  // Stores quotient value
	if (*head2 == NULL || (*head2)->data == 0 && (*head2)->next == NULL)
	{
		return FAILURE; // Division by zero check
	}
	if (list_compare(*head1, *head2) == FAILURE) // Check if dividend is smaller than divisor
	{
		dl_insert_first(headR, tailR, 0); // Dividend smaller than divisor → quotient is 0
	}
	while (list_compare(*head1, *head2) != FAILURE) // Loop while dividend greater divisor
	{
		subtraction(head1, tail1, head2, tail2, headR, tailR); // Subtract divisor from dividend
		count++; // Increase quotient count
		dl_delete_list(head1, tail1); // delete old dividend list
		*head1 = *headR; // Update dividend with subtraction result
		*tail1 = *tailR;
		*headR = NULL; // Reset result list for next iteration
		*tailR = NULL;
	}
	dl_insert_first(headR, tailR, count); // Insert final quotient into result list
	return SUCCESS;
}
