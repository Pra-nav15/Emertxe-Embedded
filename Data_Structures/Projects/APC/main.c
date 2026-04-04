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
	Dlist* head1 = NULL, * tail1 = NULL; // Linked list for first operand
	Dlist* head2 = NULL, * tail2 = NULL;  // Linked list for second operand
	Dlist* headR = NULL, * tailR = NULL; // Linked list for result
	if (argc != 4)
	{
		printf("\033[1;32mUsage: ./a.out <num1> <operator> <num2>\033[0m\n");
		return 1;
	}
    printf("\n\033[1;32m=========================================================\033[0m\n");
    printf("\033[1;33m           Arbitrary Precision Calculator            \033[0m\n");
    printf("\033[1;32m=========================================================\033[0m\n");
    printf("\033[1;36m Operand 1  : \033[1;37m%-15s\033[0m\n", argv[1]);
    printf("\033[1;36m Operand 2  : \033[1;37m%-15s\033[0m\n", argv[3]);
    printf("\033[1;36m Operator   : \033[1;37m%-15c\033[0m\n", argv[2][0]);
	char operator=argv[2][0]; // Extract operator from command-line argument
	if (operator != '+' && operator != '-' && operator != 'x' && operator != '/')  // validate operator
	{
		printf("\033[1;31mError! Undefined Operator : '%c'\033[0m\n", operator);
		printf("\033[1;35mOperators: + - x /\033[0m\n");
		return FAILURE;
	}
	int result_sign = 1; //store the sign of result
    // Extract signs BEFORE calling digit_to_list
	int sign1, sign2;
    if (argv[1][0] == '-')  // check if first operand is negative
    {
        sign1 = -1;
    }
    else
    {
        sign1 = 1;  // positive by default
    }
    if (argv[3][0] == '-')  // check if second operand is negative
    {
        sign2 = -1;
    }
    else
    {
        sign2 = 1;  // positive by default
    }
    digit_to_list(&head1, &tail1, &head2, &tail2, argv);  // Convert input digits to lists
    switch (operator)
    {
        case '+':
            if (sign1 == sign2)  // both same sign: add magnitudes, keep the sign
            {
                result_sign = sign1;
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            }
            else  // different signs: subtract smaller magnitude from larger
            {
                if (list_compare(head1, head2) >= 0)  // head1 has larger or equal magnitude
                {
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    result_sign = sign1;  // result takes sign of larger magnitude
                }
                else  // head2 has larger magnitude
                {
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    result_sign = sign2;  // result takes sign of larger magnitude
                }
            }
            break;

        case '-':
            sign2 = -sign2;  // negate sign2 to convert a-b into a+(-b)
            if (sign1 == sign2)  // both same sign after flip: add magnitudes
            {
                result_sign = sign1;
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            }
            else  // different signs after flip: subtract smaller from larger
            {
                if (list_compare(head1, head2) >= 0)  // head1 has larger or equal magnitude
                {
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    result_sign = sign1;  // result takes sign of larger magnitude
                }
                else  // head2 has larger magnitude
                {
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    result_sign = sign2;  // result takes sign of larger magnitude
                }
            }
            break;
		case 'x':
			result_sign = sign1 * sign2;
			/* call the function to perform the multiplication operation */
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			break;
		case '/':
			/* call the function to perform the division operation */
			result_sign = sign1 * sign2;
			if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE) // Handle Division Error
			{
				printf("\033[1;31mUndefined Result..\033[0m\n");
				return FAILURE;
			}
			break;
		default:
			printf("\033[1;31mInvalid Input:-( Try again...\033[0m\n");
			return FAILURE;
	}
    printf("\033[1;36m Result     : \033[0m");  // magenta for result value
    if (result_sign == -1)
    {
        printf("-");
    }
    print_list(headR);  // display the result list
	return 0;
}
