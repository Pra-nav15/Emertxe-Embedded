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
int insert_before(Slist**,int,int);
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
        insert_at_first(&head, arr[i]);
    }
    printf("List before Inserting new data before given data is :\n");
    printlist(head);
    int given_data;
    int new_data;
    printf("Enter the Given Data and New Data :");
    scanf("%d %d", &given_data, &new_data);
    if (insert_before(&head, given_data, new_data) == SUCCESS)
    {
        printf("List after Inserting new data before given data is :\n");
        printlist(head);
        return SUCCESS;
    }
    else
    {
        printf("%d is not present in the given list\n", given_data);
        return FAILURE;
    }
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
int insert_before(Slist** head, int given_data, int new_data)
{
    Slist* temp = malloc(sizeof(Slist));
    temp = *head;
    Slist* prev = temp;
    prev = NULL;
    while (temp != NULL)
    {
        if (given_data == temp->data)
        {
            Slist* new = malloc(sizeof(Slist));
            if (new == NULL)
            {
                printf("Memory Allocation Failed");
                return FAILURE;
            }
            new->data = new_data;
            new->link = temp;
            prev->link = new;
            return SUCCESS;
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
    return FAILURE;
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

