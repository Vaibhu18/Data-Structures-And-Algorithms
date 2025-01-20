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

void insertNewNode(Node *&head, Node *&tail, int data)
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

void deleteNode(Node *&head, int val)
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

void searchNode(Node *head, int data)
{
    Node *temp = head;
    bool flag = false;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            flag = true;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if(flag){
        cout<<"Elememt present in LL"<<endl;
    }else{
        cout<<"Element Not present in LL"<<endl;
    }
}

void print(Node *head)
{
    Node *temp = head;
    cout<<"your LL is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    int choice = 0;
    do
    {
        cout << "\n-----------------------" << endl;
        cout <<"Operations on Skip list" << endl;
        cout <<"-----------------------" << endl;
        cout << "1.Insert Element" << endl;
        cout << "2.Delete Element" << endl;
        cout << "3.Search Element" << endl;
        cout << "4.Display List " << endl;
        cout << "5.Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> val;
            insertNewNode(head, tail, val);
            cout << "Element successfully inserted" << endl;
            break;
        case 2:
            cout << "Enter the element to be deleted: ";
            cin >> val;
            deleteNode(head, val);
            cout << "Element deleted successfully" << endl;
            break;
        case 3:
            cout << "Enter the element to be searched: ";
            cin >> val;
            searchNode(head, val);
            break;
        case 4:
            print(head);
        }
    } while (choice != 5);
}