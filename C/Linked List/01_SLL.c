#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void createSLL(NODE **head)
{
    NODE *tail = NULL, *newNode;
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

int searchNode(NODE *head, int key)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        if (head->data == key)
        {
            return count;
        }
        head = head->next;
    }
    return -1;
}

void deleteNodeByPosition(NODE **head, int position)
{

    if (position < 0)
        return;

    if (position == 1)
    {
        *head = (*head)->next;
        return;
    }

    int count = 1;
    NODE *temp = *head;
    while (temp != NULL && count < position - 1)
    {
        count++;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    temp->next = temp->next->next;
}

void displaySLL(NODE *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void main()
{
    NODE *head = NULL;

    createSLL(&head);
    // printf("Element present at %d position", searchNode(head, 50));
    displaySLL(head);
    deleteNodeByPosition(&head, 5);
    printf("\n");
    displaySLL(head);
}