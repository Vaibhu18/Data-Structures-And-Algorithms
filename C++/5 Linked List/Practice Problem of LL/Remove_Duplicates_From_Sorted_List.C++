// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=1

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is Empty" << endl;
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *toDeleteNode = curr->next;
            delete toDeleteNode;
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *newNode = NULL;
    Node *tail = newNode;
    Node *head = newNode;

    insertNode(head, tail, 1);
    insertNode(head, tail, 2);
    insertNode(head, tail, 2);
    insertNode(head, tail, 3);
    insertNode(head, tail, 4);
    insertNode(head, tail, 4);
    insertNode(head, tail, 5);

    // cout << head->data;

    print(removeDuplicates(head));
}