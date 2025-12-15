#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int count = 0;
	if (list_compare(*head1, *head2) == LESSER)
	{
		dl_insert_first(headR, tailR, 0);
		return SUCCESS;
	}
	if (list_compare(*head1, *head2) == EQUAL)
	{
		dl_insert_first(headR, tailR, 1);
		return SUCCESS;
	}
	while(list_compare(*head1, *head2) != LESSER)
	{
		subtraction(head1, tail1, head2, tail2, headR, tailR);
		count++;
		dl_delete_list(head1, tail1);
		*head1 = *headR;
		*tail1 = *tailR;
		*headR = NULL;
		*tailR = NULL;
	}
	dl_insert_first(headR, tailR, count);
	return SUCCESS;
}
