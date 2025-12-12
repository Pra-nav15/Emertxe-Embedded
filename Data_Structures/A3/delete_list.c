
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;
int dl_delete_list(Dlist** head, Dlist** tail);
int main()
{
    	printf("Enter the element you have to insert at the first : ");
				scanf("%d", &data);
				if (dl_insert_first(&head, &tail, data) == FAILURE)
				{
					printf("INFO : Insertion Failure\n");
				}
    Dlist* head = NULL;
   Dlist* tail = NULL;
    if (dl_delete_list(&head, &tail) == FAILURE)
    {
        printf("INFO : Delete list Failure, List is empty\n");
    }
    else
    {
        printf("INFO : Delete list Successfull\n");
    }
}
int dl_delete_list(Dlist **head, Dlist **tail)
{
  if(*head == *tail)
  {
      return FAILURE;
  }
  else
  {
      Dlist *temp = malloc(sizeof(Dlist));
      while(*head != *tail)
      {
          *temp = *head;
          (*head)->next = NULL;
          *head = temp->next;
          free(temp);
      }
      *temp = *head;
      free(temp);
      return SUCCESS;
  }
}