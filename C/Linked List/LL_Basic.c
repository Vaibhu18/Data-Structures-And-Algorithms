#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void main()
{

    // Creating nodes
    // printf("Enter number : ");
    // LL = (struct Node *)malloc(sizeof(struct Node));
    // scanf("%d", &LL->data);
    // LL->next = NULL;
    // head = LL;

    // newNode = (struct Node *)malloc(sizeof(struct Node));
    // scanf("%d", &newNode->data);
    // newNode->next = NULL;
    // LL->next = newNode;
    // LL = newNode;

    // newNode = (struct Node *)malloc(sizeof(struct Node));
    // scanf("%d", &newNode->data);
    // newNode->next = NULL;
    // LL->next = newNode;

    struct Node *head = NULL, *LL = NULL, *newNode = NULL, *printingNode = NULL;
    int flag = 1;
    int num;

    while (flag == 1)
    {
        printf("Enter a new Number : ");
        newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &num);

        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            LL = newNode;
        }
        else
        {
            LL->next = newNode;
            LL = newNode;
        }
        printingNode = head;
        while (printingNode != NULL)
        {
            printf("%d -> ", printingNode->data);
            printingNode = printingNode->next;
        }
    }
}