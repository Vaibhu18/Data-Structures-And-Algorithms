#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef, poly;
    struct node *next;
} NODE;

void createNode1(NODE **eqe)
{
    NODE *tail;
    int n;
    printf("length of polynomial equation : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        printf("Enter coefficient : ");
        scanf("%d", &newNode->coef);
        printf("Enter Power : ");
        scanf("%d", &newNode->poly);
        newNode->next = NULL;

        if (*eqe == NULL)
        {
            tail = newNode;
            *eqe = tail;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void mergePoly(NODE *eqe1, NODE *eqe2, NODE **eqe3)
{
    NODE *tail, *newNode;
    while (eqe1 != NULL && eqe2 != NULL)
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        if (eqe1->poly == eqe2->poly)
        {
            newNode->coef = eqe1->coef + eqe2->coef;
            newNode->poly = eqe1->poly;
            newNode->next = NULL;
            if (*eqe3 == NULL)
            {
                tail = newNode;
                *eqe3 = tail;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            eqe1 = eqe1->next;
            eqe2 = eqe2->next;
        }
        else if (eqe1->poly > eqe2->poly)
        {
            newNode->coef = eqe1->coef;
            newNode->poly = eqe1->poly;
            newNode->next = NULL;
            if (*eqe3 == NULL)
            {
                tail = newNode;
                *eqe3 = tail;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            eqe1 = eqe1->next;
        }
        else
        {
            newNode->coef = eqe2->coef;
            newNode->poly = eqe2->poly;
            newNode->next = NULL;
            if (*eqe3 == NULL)
            {
                tail = newNode;
                *eqe3 = tail;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            eqe2 = eqe2->next;
        }
    }

    while (eqe1 != NULL)
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        newNode->coef = eqe1->coef;
        newNode->poly = eqe1->poly;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
        eqe1 = eqe1->next;
    }

    while (eqe2 != NULL)
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        newNode->coef = eqe2->coef;
        newNode->poly = eqe2->poly;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
        eqe2 = eqe2->next;
    }
}

void display(NODE *eqe2)
{
    NODE *tail = eqe2;
    while (tail != NULL)
    {
        printf("%dx^%d ", tail->coef, tail->poly);
        tail = tail->next;
    }
}

int main()
{
    NODE *eqe1 = NULL, *eqe2 = NULL, *eqe3 = NULL;
    printf("Enter data for 1st equation\n");
    createNode1(&eqe1);
    printf("Enter data for 2nd equation\n");
    createNode1(&eqe2);

    mergePoly(eqe1, eqe2, &eqe3);

    display(eqe1);
    printf("\n");
    display(eqe2);
    printf("\n");
    display(eqe3);

    return 0;
}