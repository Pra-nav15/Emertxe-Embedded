
#include "apc.h"
int flag = 0;
int compare = 0;
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
					Dlist *t1 = head1;
					Dlist *t2 = head2;
					int list1_count = 0;
					int list2_count = 0;
					while (t1 != NULL)
					{
						list1_count++;
						t1 = t1->next;
					}
					while (t2 != NULL)
					{
						list2_count++;
						t2 = t2->next;
					}
					if (list1_count > list2_count)
					{
						subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					}
					else if (list1_count < list2_count)
					{
						flag = 1;
						subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
					}
					else
					{
						t1 = head1;
						t2 = head2;
						while (t1 != NULL && t2 != NULL)
						{
							if (t1->data > t2->data)
							{
								compare = 0;
								break;
							}
							else if (t1->data < t2->data)
							{
								compare = 1;
								break;
							}
							t1 = t1->next;
							t2 = t2->next;
						}
						if (compare == 0)
						{
							subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
						}
						else if (compare == 1)
						{
							subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
							flag = 1;
						}
					}
					if (flag == 1)
					{
						printf("-");
					}
					print_list(headR);
				/* call the function to perform the subtraction operation */
				break;
			case '*':	
				/* call the function to perform the multiplication operation */
				break;
			case '/':	
				/* call the function to perform the division operation */
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		return 0;
}
