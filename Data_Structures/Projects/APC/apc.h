#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 0
#define FAILURE -1

/* create a node to list*/
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*To store the operands we use insert at last*/
int dl_insert_last(Dlist** head, Dlist** tail, int data);

/*To store the result we use insert at first*/
int dl_insert_first(Dlist** head, Dlist** tail, int data);

/*To print the result*/
void print_list(Dlist* head);

/*To delete the list*/
int dl_delete_list(Dlist** head, Dlist** tail);

/*To compare two lists*/
int list_compare(Dlist* head1, Dlist* head2);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif
