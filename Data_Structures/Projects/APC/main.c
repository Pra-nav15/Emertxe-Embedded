/*
                         Project Documentation- Arbitrary Precision Calculator(APC)
Name: Pranav Prasad
Date: 18/12/2025
Description:
• This project is a Command Line Based Arbitrary Precision Calculator implemented in C.
• Arbitrary precision arithmetic allows calculations on very large numbers whose size is limited only by available system memory.
• The system performs arithmetic operations on big integers that cannot be handled using standard C data types.
• This project uses a Doubly Linked List to store each digit of large numbers.
• User input is given via command line in the form of two big numbers with an operator between them.
• The program automatically identifies the operator and performs the corresponding arithmetic operation.
• Supported operations include Addition (+), Subtraction (-), Multiplication (*), and Division (/).
• Each operand is sliced digit by digit and stored across different nodes of the linked list.
• Arithmetic operations are performed similar to manual calculation, handling carry forward, borrow, and positional shifts.
• During division, repeated subtraction is used to compute the quotient safely.
• Special cases such as zero inputs, division by zero, and unequal number sizes are handled explicitly.
• The program compares operands before subtraction and division to ensure correct results.
• This system is useful for cryptographic applications, scientific calculations, and learning big-number arithmetic.
• Advantages include unlimited number size support, accurate results without overflow, and modular code structure.
• This project uses dynamic memory allocation, pointers, structures, and command-line arguments are used.
• This project helps in understanding how large-number arithmetic is implemented internally using data structures.
*/
#include "apc.h"

int main(int argc, char* argv[])
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL; // Linked list for first operand
	Dlist *head2=NULL, *tail2=NULL;  // Linked list for second operand
	Dlist *headR=NULL,*tailR=NULL; // Linked list for result
	char operator=argv[2][0]; // Extract operator from command-line argument
	int result_sign = 0; //store the sign of result
	digit_to_list(&head1, &tail1, &head2, &tail2, argv);  // Convert input digits to lists
	switch (operator)
	{
	    case '+':
		        /* call the function to perform the addition operation */
		        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
		case '-':
				if (list_compare(head1, head2) != FAILURE) // head1 >= head2
				{
					/* call the function to perform the subtraction operation */
					subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}
				else // head1 < head2
				{
					subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
					result_sign = -1;
				}
		break;
		case 'x':	
				/* call the function to perform the multiplication operation */
				multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
		case '/':	
				/* call the function to perform the division operation */
				if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE) // Handle Division Error
				{
					printf("Undefined Result..\n"); 
					return FAILURE;
				}
		break;
		default:
				printf("Invalid Input:-( Try again...\n");
	}
	if(result_sign == -1)
	{
		printf("-");
	}
    print_list(headR);//display the Result List
	return 0;
}
