//https://www.codingninjas.com/codestudio/problems/merge-sort-linked-list_920473?leftPanelTab=1

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
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node* mergeLL(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    return ans;
}

Node* sortLL(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* mid = getMid(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    left = sortLL(left);
    right = sortLL(right);

    Node* res = mergeLL(left, right);
    res = res -> next;
    return res;

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
    
    insertNewNode(head, tail, 1);
    insertNewNode(head, tail, -2);
    insertNewNode(head, tail, 3);
      
    print(sortLL(head));
}