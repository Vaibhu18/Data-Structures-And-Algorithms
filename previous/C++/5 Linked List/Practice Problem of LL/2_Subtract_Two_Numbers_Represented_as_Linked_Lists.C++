#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
int sub(Node *&head)
{
    head->data += 10;
    head->next->data -= 1;
}

Node *multiple(Node *first, Node *second)
{
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }

        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        if (val1 - val2 < 0 && first->next != NULL)
        {
            val1 += 10;
            int val = first->next->data;
            first->next->data = val - 1;
        }
        int sum = val1 - val2;
        insertAtTail(ansHead, ansTail, sum);
        
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return ansHead;
}

Node *reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *addNum(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);
    Node *ans = multiple(first, second);
    ans = reverse(ans);
    return ans;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *newNode = new Node(4);
    Node *first = newNode;
    Node *tail = newNode;
    insertAtTail(first, tail, 0);
    insertAtTail(first, tail, 3);

    Node *newNode2 = new Node(1);
    Node *second = newNode2;
    Node *stail = newNode2;
    insertAtTail(second, stail, 2);
    insertAtTail(second, stail, 5);

    print(addNum(first, second));
}