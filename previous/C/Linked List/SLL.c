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
void insertFirst(int);
void insertLast(int);
void deleteAtPosition(int);
void deleteFirst();
void deleteLast();
int lengthSLL();

void main()
{
    createSLL();
    printSLL();
    // insert at position
    // insertAtPosition(8, 20);
    // deleteAtPosition(6);
    // insertFirst(20);
    // insertLast(20);
    // deleteFirst();
    // deleteLast();
    // printSLL();
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

void insertFirst(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = Head;
    Head = newNode;
}

void insertLast(int data)
{
    struct Node *currentNode = Head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void deleteFirst()
{
    Head = Head->next;
}
void deleteLast()
{
    struct Node *currentNode = Head;
    while (currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = NULL;
}

void deleteAtPosition(int position)
{
    struct Node *currentNode = Head;
    if (position == 1)
    {
        currentNode = currentNode->next;
        Head = currentNode;
        return;
    }
    if (position > lengthSLL() || position < 1)
    {
        printf("\nError : Invalid position");
        return;
    }
    struct Node *temp = NULL;
    int len = 1;
    while (len < position - 1)
    {
        len++;
        currentNode = currentNode->next;
    }
    currentNode->next = currentNode->next->next;
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