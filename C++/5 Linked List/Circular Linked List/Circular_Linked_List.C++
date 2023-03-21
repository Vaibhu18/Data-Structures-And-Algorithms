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

    // Distructor
    ~Node()
    {
        int val = this->data;
        while (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Deleted Node is : " << val << endl;
    }
};

// Insert Node at last of CLL
void insertNode(Node *head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

// Insert Node in front of given element
void insertAtAnyPosition(Node *&head, int ele, int data)
{
    if (head == NULL)
    {
        return;
    }

    if (head->data == ele)
    {
        Node *newNode = new Node(data);
        newNode->next = head->next;
        head->next = newNode;
    }
    else
    {
        Node *temp = head->next;
        while (temp != head && temp->data != ele)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete Node by given value
void deleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node *newNode = new Node(1);
    Node *head = newNode;
    Node *tail = newNode;
    for (int i = 2; i <= 5; i++)
    {
        insertNode(head, tail, i);
    }
    // insertAtAnyPosition(head, 5, 25);
    deleteNode(head, 3);
    print(head);
}