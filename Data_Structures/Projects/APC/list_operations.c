#include "apc.h"

int dl_insert_first(Dlist** head, Dlist** tail, int data)
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
       new->next = *head;
       (*head)->prev= new;
       *head = new;
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
       new->prev = *tail;
       (*tail)->next = new;
       *tail = new;
       return SUCCESS;
   }
}

int dl_delete_list(Dlist** head, Dlist** tail)
{
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }
    else
    {
        Dlist* temp;
        while (*head != NULL)
        {
            temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
}

int list_compare(Dlist* head1, Dlist* head2)
{
    Dlist* t1 = head1;
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
        return GREATER;
    }
    else if (list1_count < list2_count)
    {
        return LESSER;
    }
    else
    {
        t1 = head1;
        t2 = head2;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->data > t2->data)
            {
                return GREATER;
            }
            else if (t1->data < t2->data)
            {
                 return LESSER;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return EQUAL;
    }
}