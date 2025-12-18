
#include "apc.h"
int main(int argc, char* argv[])
{
	/* Declare the pointers */
      
	    Dlist *head1=NULL, *tail1=NULL;
        Dlist *head2=NULL, *tail2=NULL; 
        Dlist *headR=NULL,*tailR=NULL;
		char operator=argv[2][0];
		switch (operator)
		{
			case '+':
					digit_to_list(&head1,&tail1,&head2,&tail2,argv);
					/* call the function to perform the addition operation */
					addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					print_list(headR);
					break;
			case '-':
				digit_to_list(&head1, &tail1, &head2, &tail2, argv);
				if (list_compare(head1, head2) == SUCCESS)
				{
				   subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}
				else if (list_compare(head1, head2) == FAILURE)
				{
					subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
					printf("-");
				}
				print_list(headR);
				/* call the function to perform the subtraction operation */
				break;
			case 'x':	
				/* call the function to perform the multiplication operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				print_list(headR);
				break;
			case '/':	
				/* call the function to perform the division operation */
				digit_to_list(&head1, &tail1, &head2, &tail2, argv);
				if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
				{
					printf("Output Cannot be Obtained\n");
					return FAILURE;
				}
				print_list(headR);
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		return 0;
}
