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

// Insert Node at starting of the linked list
void insertAtFirst(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insert Node at ending of the linked list
void insertAtLast(Node *&head, int data)
{
    Node *newNode = new Node(data);
    head->next = newNode;
    head = newNode;
}


// Insert Node at any position of the linked list
void insertAtMiddle(Node* &tail, Node *&head, int position, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);
    int i = 1;
    if (position == 1)
    {
        insertAtFirst(head, data);
        return;
    }
    else if (head == NULL)
    {
        insertAtLast(head, data);
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        Node* p = head;
        int count = 1;
        int i = 1;
        while(p != NULL){
            count++;
            p = p->next;
        }
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        if(count > position){
            newNode->next = temp->next;
            temp->next = newNode;
        }else{
            insertAtLast(tail, data);
        }     
    }
}


// Delete first Node of the linked list
void deleteAtFirst(Node *&head)
{
    Node *temp = head;
    head = temp->next;
}


// Delete last Node of the linked list
void deleteAtLast(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// Delete Node by any value of the linked list
void deleteByValue(Node *&head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            head = temp->next;
            break;
        }
        else if (temp->next->data == val)
        {
            temp->next = temp->next->next;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}


// Delete Node by Position of the linked list
void deleteByPosition(Node *&head, int pos)
{
    Node *temp = head;
    int i = 1;
    if (i == pos)
    {
        head = temp->next;
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }
}

// get length of LL
int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}



// Print Linked List
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
    Node *newNode = new Node(10);
    Node *head = newNode;
    Node *tail = newNode;
    insertAtFirst(head, 12);
    insertAtFirst(head, 13);
    insertAtLast(tail, 9);
    insertAtLast(tail, 8);
    // print(head);
    // cout<<endl;
    // deleteAtFirst(head);
    // deleteAtLast(head);
    // deleteByValue(head, 9);
    // deleteByPosition(head, 6);
    insertAtMiddle(tail, head, 7, 100);
    

    print(head);
    cout << endl;
    cout<<"Length of LL is : "<<getLength(head);
}