#define FAILURE 0
#define SUCCESS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Slist;
int insert_at_last(Slist**, int);
void printlist(Slist* head);
int main()
{
    Slist* head = NULL;
    int arr[5];
    printf("Enter the elements needed to be Inserted in the List:\n");
    for (int i = 0;i < 5;i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0;i < 5;i++)
    {
        insert_at_last(&head, arr[i]);
    }
    printf("List before Inserting at Last:\n");
    printlist(head);
    int data;
    printf("Enter the Data to be inserted: ");
    scanf("%d", &data);
    printf("List After Inserting at Last:\n");
    insert_at_last(&head, data);
    printlist(head);
    return 0;
}
int insert_at_last(Slist** head, int data)
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
    else
    {
        Slist* temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
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

