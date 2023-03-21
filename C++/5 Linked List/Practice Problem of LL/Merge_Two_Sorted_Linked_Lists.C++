// https://www.codingninjas.com/codestudio/problems/800332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
// https://leetcode.com/problems/merge-two-sorted-lists/submissions/894516894/

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

Node* mergeLL(Node* &first, Node* &second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if( (curr2 ->data >= curr1 -> data) && curr2 -> data <= next1 -> data ){
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }else{
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
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
    Node *newNode1 = new Node(1);
    Node *first = newNode1;
    Node *firstTail = newNode1;
    createLL(firstTail, 3);
    createLL(firstTail, 5);

    Node *newNode2 = new Node(2);
    Node *second = newNode2;
    Node *secondTail = newNode2;
    createLL(secondTail, 4);
    createLL(secondTail, 5);

    if(first -> data <= second -> data){
        print(mergeLL(first, second));
    }else{
        print(mergeLL(second, first));
    }
}