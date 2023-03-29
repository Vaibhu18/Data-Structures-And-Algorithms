

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void createNode(node *&root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data for left of " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

vector<int> rightSideView(node* root, vector<int>&ans){
    queue<node*>q;
    int val = 0;
    if(root== NULL){
        return ans;
    }
        q.push(root);
        q.push(NULL);
            
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            val = 0;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(val == 0){
                cout<<temp->data<<" ";  
            }
            val++;
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return ans;
}

vector<int> leftSideView(node* root, vector<int>&ans){
    queue<node*>q;
    int val = 0;
    if(root== NULL){
        return ans;
    }
        q.push(root);
        q.push(NULL);
            
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<val<<" ";
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            val = temp->data;
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return ans;
}


int main()
{
    node *root = NULL;
    vector<int>ans;
    createNode(root);
    cout<<"Right side view : ";
    rightSideView(root, ans);
    cout<<endl;
    cout<<"Left side view : ";
    leftSideView(root, ans);

}

// 1 2 3 -1 -1 4 5 -1 -1 -1 -1