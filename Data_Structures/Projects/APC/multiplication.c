#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // Performs large-number multiplication using digit-wise linked-list traversal similar to manual multiplication
    Dlist* headR1 = NULL; // Stores partial product for current digit of number2
	Dlist* tailR1 = NULL;
	Dlist* headR2 = NULL;  // Stores cumulative multiplication result
	Dlist* tailR2 = NULL;
	Dlist* temp1 = NULL; // Pointer to traverse first number
	Dlist* temp2 = *tail2;  // Pointer to traverse one's side digit of number2
	int carry = 0, result = 0, count = 0;
    *headR = NULL;  // Clear final result list
    *tailR = NULL;
    while (temp2 != NULL) // Loop for each digit of second number
    {
		carry = 0; // Reset carry for each partial multiplication
		temp1 = *tail1;   // Start from one's side digit of first number
		for (int i = 0; i < count; i++)
        {
            dl_insert_first(&headR1, &tailR1, 0); // Add zeros for positional shift
        }
        while (temp1 != NULL) // Traverse for Multiply current digit with all digits of first number
        {
            result = (temp1->data * temp2->data) + carry; // Multiply and add carry
            carry = result / 10; //Update Carry
            result = result % 10; // Get single digit
            dl_insert_first(&headR1, &tailR1, result); // Store digit in partial result
            temp1 = temp1->prev;  // Move to next digit
        }
        if (carry > 0)
        {
            dl_insert_first(&headR1, &tailR1, carry); // Insert remaining carry
        }
        if (headR2 == NULL)
        {
            headR2 = headR1;  // First partial result becomes base result
            tailR2 = tailR1;
        }
        else
        {
            addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR); // Add partial result to total
            dl_delete_list(&headR1, &tailR1); // Delete old partial result list
            dl_delete_list(&headR2, &tailR2); // Delete old result list
            headR2 = *headR;  // Update accumulated result
            tailR2 = *tailR;
            *headR = NULL;  // Reset result pointers
            *tailR = NULL;
        }
        headR1 = NULL; // Clear partial result list
        tailR1 = NULL;
        count++;  // Increment position shift
        temp2 = temp2->prev; // Move to next digit of second number
    }
    *headR = headR2; // Assign final result head
    *tailR = tailR2; // Assign final result tail
    return SUCCESS;
}
