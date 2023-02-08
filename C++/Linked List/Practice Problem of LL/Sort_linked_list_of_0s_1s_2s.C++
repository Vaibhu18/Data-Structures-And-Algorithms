// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1

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

void createLL(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// 1st Approach [ T.C = O(n) / S.C = O(1) ]
Node *sortLL1(Node *&head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

// 2nd Approach [ T.C = O(n) / S.C = O(1) ]
void insertNode(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node *sortLL2(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node* temp = head;
    while(temp != NULL){
        int val = temp -> data;
        if(val == 0){
            insertNode(zeroTail, temp);
        }else if(val == 1){
            insertNode(oneTail, temp);
        }else if(val == 2){
            insertNode(twoTail, temp);
        }
        temp = temp -> next;
    }
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }else{
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead ->next;
    twoTail -> next = NULL;
    head = zeroHead -> next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
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
    Node *newNode = new Node(0);
    Node *head = newNode;
    Node *tail = newNode;

    createLL(tail, 1);
    createLL(tail, 1);
    createLL(tail, 2);
    createLL(tail, 0);

    print(sortLL1(head));
    cout<<endl;
    print(sortLL2(head));
}