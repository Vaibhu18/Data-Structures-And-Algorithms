#include <iostream>
#include <vector>
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

// 1st Approach [ T.C = O(n) & S.C = O(n) ]

bool checkPalindrome(vector<int>arr){
    int n = arr.size();
    int start = 0;
    int end = n-1;
    while(start <= end){
        if(arr[start] != arr[end]){
            return 0;
        }else{
            start++;
            end--;
        }
    }
    return true;
}

bool isPalindrome1(Node* head){
    vector<int>arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkPalindrome(arr);
}

// 2nd Approach [ T.C = O(n) & S.C = O(1) ]
Node* getMiddle(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome2(Node* head){
    if(head -> next == NULL){
        return true;
    }
    // step 1 find middle of LL
    Node* Middle = getMiddle(head);
    Node* temp = Middle -> next;

    // step 2 reverse LL from Middle
    Middle -> next = reverseLL(temp);

    // step 3 Compare Normal and reversed LL
    Node* head1 = head;
    Node* head2 = Middle -> next;
    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            return false;
        }else{
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }
    return true;
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
    Node *head = newNode1;
    Node *tail = newNode1;
    createLL(tail, 2);
    createLL(tail, 3);
    createLL(tail, 3);
    createLL(tail, 2);
    createLL(tail, 1);

// print(head);
   cout<<isPalindrome2(head)<<endl;

}