#define FAILURE 0
#define SUCCESS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Slist;
int insert_at_first(Slist**, int);
void printlist(Slist* head);
int main()
{
    Slist* head = NULL;
    int arr[5];
    for (int i = 0;i < 5;i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0;i < 5;i++)
    {
        insert_at_first(&head, arr[i]);
    }
    printf("List before Inserting at First:\n");
    printlist(head);
    int data = 25;
    insert_at_first(&head, data);
    printf("List After Inserting at First:\n");
    printlist(head);
    return 0;
}
int insert_at_first(Slist** head, int data)
{
    Slist* new = malloc(sizeof(Slist));
    if (new == NULL)
    {
        printf("Memory Allocation Failed");
        return FAILURE;
    }
    new->data = data;
    new->link = NULL;
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    new->link = *head;
    *head = new;
    return SUCCESS;
}
void printlist(Slist* head)
{
    if (head == NULL)
    {
        printf("INFO : List is empty\n");
    }
    else
    {
        while (head)
        {
            printf("%d ", head->data);
            head = head->link;
        }
        printf("\n");
    }
}

