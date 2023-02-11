// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
}

Node* addNumbers(Node* first, Node* second){
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while(first != NULL || second != NULL || carry != 0){

        int val1 = 0;
        if(first != NULL){
            val1 = first -> data;
        }

        int val2 = 0;
        if(second != NULL){
            val2 = second -> data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        if(first != NULL){
            first = first -> next;
        }
        if(second != NULL){
            second = second -> next;
        }
    }
    return ansHead;
}
Node *reverse(Node *head)
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

Node *AddTwoNumbers(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);

    Node* ans = addNumbers(first, second);
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
    Node *newNode1 = new Node(6);
    Node *first = newNode1;
    Node *firstTail = newNode1;
    createLL(firstTail, 3);

    Node *newNode2 = new Node(7);
    Node *second = newNode2;
    Node *secondTail = newNode2;
    // createLL(secondTail, 4);
    // createLL(secondTail, 5);

    print(AddTwoNumbers(first, second));
}