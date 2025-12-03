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
int delete_at_first(Slist**);
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
    printf("List Before Delete First Element: \n");
    printlist(head);
    delete_at_first(&head);
    printf("List After Delete First Element: \n");
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
int delete_at_first(Slist** head)
{
    if (head == NULL)
    {
        return FAILURE;
    }
    else
    {
        Slist* temp = *head;
        *head = temp->link;
        free(temp);
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

