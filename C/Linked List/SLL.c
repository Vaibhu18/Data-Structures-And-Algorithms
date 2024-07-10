#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head = NULL;
void createSLL();
void printSLL();
void insertAtPosition(int, int);
int lengthSLL();

void main()
{
    createSLL();
    printSLL();

    // insert at position
    insertAtPosition(8, 20);
    printSLL();
    printf("\nSLL length : %d", lengthSLL());
}

void createSLL()
{
    struct Node *currentNode = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (Head == NULL)
        {
            Head = newNode;
            currentNode = Head;
        }
        else
        {
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }
}

void insertAtPosition(int position, int data)
{
    if (position > lengthSLL() + 1 || position < 1)
    {
        printf("\nError : Invalid position");
        return;
    }
    struct Node *currentNode = Head;
    int len = 1;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = Head;
        Head = newNode;
    }
    else
    {
        while (len < position - 1)
        {
            len++;
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

void printSLL()
{
    struct Node *currentNode = Head;

    printf("\nSLL : ");
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
}
int lengthSLL()
{
    struct Node *currentNode = Head;
    int len = 0;
    while (currentNode != NULL)
    {
        len++;
        currentNode = currentNode->next;
    }
    return len;
}