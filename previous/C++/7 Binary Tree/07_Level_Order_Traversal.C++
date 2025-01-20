


#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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

void buidFromLevelOrder(node* &root){
    cout<<"Enter data to root : ";
    int data;
    cin>>data;
    root = new node(data);
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Binary Tree Level Order Traversal
void levelOrder(node* root){
    vector<int> ans;
    vector<int>v;

    if(root == NULL){
        ans.push_back(0);
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            while(!v.empty()){
                    int ele = v.front();
                    v.erase(v.begin());
                    ans.push_back(ele);
                }
                if(!q.empty()){
                    q.push(NULL);
                }
        }else{
            v.push_back(root->data);
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
    }
    while(!ans.empty()){
        int ele = ans.front();
        cout<<ele<<" ";
        ans.erase(ans.begin());
    }
}

int main(){
    node* root = NULL;
    buidFromLevelOrder(root);
    levelOrder(root);
}