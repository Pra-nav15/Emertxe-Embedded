#include "apc.h"

int dl_insert_first(Dlist** head, Dlist** tail, int data)
{
   Dlist *new = malloc(sizeof(Dlist)); // Allocate memory for new node
   if(new == NULL)
   {
       return FAILURE; // Return failure if memory allocation fails
   }
   new->data = data; // Assign data to node
   new->next = NULL; // Initialize next pointer
   new->prev = NULL; // Initialize previous pointer
   if(*head == NULL && *tail == NULL)  // Check if list is empty
   {
       *head=new;  // New node becomes head
       *tail=new;  // New node becomes tail
       return SUCCESS;
   }
   else
   {
       new->next = *head; // Point new node to current head
       (*head)->prev= new;  // Link current head back to new node
       *head = new;   // Update head to new node
       return SUCCESS;
   }
}

int dl_insert_last(Dlist** head, Dlist** tail, int data)
{
   Dlist *new = malloc(sizeof(Dlist));
   if(new == NULL)
   {
       return FAILURE;
   }
   new->data = data;
   new->next = NULL;
   new->prev = NULL;
   if(*head == NULL && *tail == NULL) 
   {
       *head=new;
       *tail=new;
       return SUCCESS;
   }
   else
   {
       new->prev = *tail; // Link new node to current tail
       (*tail)->next = new;  // Link current tail to new node
       *tail = new; // Update tail to new node
       return SUCCESS;
   }
}

int dl_delete_list(Dlist** head, Dlist** tail)
{
    if (*head == NULL && *tail == NULL) // Check if list is already empty
    {
        return FAILURE;   // Nothing to delete
    }
    else
    {
        Dlist* temp;
        while (*head != NULL) // Traverse list from head
        {
            temp = *head; // Store current head
            *head = (*head)->next; // Move head to next node
            free(temp); // Free current node
        }
        *head = NULL;  // Reset head pointer
        *tail = NULL;  // Reset tail pointer
        return SUCCESS;
    }
}

int list_compare(Dlist* head1, Dlist* head2)
{
    Dlist* t1 = head1; // Pointer to traverse first list
    Dlist *t2 = head2;  // Pointer to traverse second list
    int list1_count = 0; // Store length of first list
    int list2_count = 0; // Store length of second list
    while (t1 != NULL)  // Count nodes in first list
    {
        list1_count++;
        t1 = t1->next;
    }
    while (t2 != NULL) // Count nodes in second list
    {
        list2_count++;
        t2 = t2->next;
    }
    if (list1_count > list2_count)  // First number has more digits
    {
        return SUCCESS; // First list is greater
    }
    else if (list1_count < list2_count) // Second number has more digits
    {
        return FAILURE; // First list is smaller
    }
    else
    {
        t1 = head1; // Reset pointer to head of first list
        t2 = head2; // Reset pointer to head of second list
        while (t1 != NULL && t2 != NULL) // Compare digit by digit
        {
            if (t1->data > t2->data) // First digit is greater
            {
                return SUCCESS;
            }
            else if (t1->data < t2->data) // Second digit is greater
            {
                 return FAILURE;
            }
            t1 = t1->next; // Move to next digit
            t2 = t2->next;
        }
    }
}