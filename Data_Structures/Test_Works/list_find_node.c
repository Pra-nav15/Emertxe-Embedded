#define FAILURE 0
#define SUCCESS 1
#define DATA_NOT_FOUND 2
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Slist;
int insert_at_first(Slist**, int);
int find_node(Slist*,int );
void printlist(Slist* head);
int count = 0;
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
    printf("List : \n");
    printlist(head);
    int given_data;
    printf("Enter data to be searched :");
    scanf("%d", &given_data);
    if (find_node(head, given_data) == SUCCESS)
    {
        printf("Node Found at index %d\n",count);
        return SUCCESS;
    }
    else
    {
        printf("Node not Found in the given List.\n");
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
int find_node(Slist* head,int given_data)
{
    if (head == NULL)
    {
        return FAILURE;
    }
    else
    {
        while (head != NULL)
        {
            if (head->data == given_data)
            {
                return SUCCESS;
            }
            else
            {
                count++;
                head = head->link;
            }
        }
        return DATA_NOT_FOUND;
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

