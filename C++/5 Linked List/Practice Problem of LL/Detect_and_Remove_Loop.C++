// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1

#include <iostream>
#include <map>
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

// Create Linked list
void insertAtLast(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// check cycle is present or not in LL ( 1st Approach using map )
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return false;
    }
    else
    {
        Node *temp = head;
        map<Node *, bool> visited;
        while (temp != NULL)
        {
            if (visited[temp] == true)
            {
                cout << "Cycle is present at " << temp->data << endl;
                return true;
            }
            else
            {
                visited[temp] = true;
                temp = temp->next;
            }
        }
        return false;
    }
}

// check cycle is present or not in LL ( 2nd Approach floyd detection algorithm )
Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    else
    {
        Node *fast = head;
        Node *slow = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast)
            {
                return slow;
            }
        }
        return NULL;
    }
}

// Get starting Node of cycle
Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    Node *intersection = floydDetectLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove loop
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return;
    }
    Node *starting = getStartingNode(head);
    Node *temp = starting;
    while (temp->next != starting)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    Node *newNode = new Node(1);
    Node *head = newNode;
    Node *tail = newNode;

    // Insert element in node
    for (int i = 2; i <= 5; i++)
    {
        insertAtLast(tail, i);
    }
    print(head);
    cout << endl;

    // Create cycle at 3 node
    tail->next = head->next->next;

    // Node*temp = floydDetectLoop(head);
    // cout <<temp->data ;

    // Node* temp = getStartingNode(head);
    // cout<<temp->data;
    removeLoop(head);
    print(head);
}

/*
T.C = O(n)
S.C = O(n)
if map space complexity is O(n) we want to decrease it thats why i use floyd detection algo
S.C = O(1)
*/