// Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/submissions/9252029

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool ans = false;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildNode(node* &root){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter data for left of : "<< temp->data<<endl;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter data for right of : "<< temp->data<<endl;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

bool match(node* root, node* subtree){
    if(root != NULL && subtree != NULL){
        bool a = match(root->left, subtree->left);
        bool b = match(root->right, subtree->right);

        if((root->data == subtree->data) && a && b){
            return true;
        }else{
            return false;
        }
    }else if (root == NULL && subtree == NULL){
        return true;
    }else{
        return false;
    }
}

void inorder(node* root, node* subtree){
    if(root != NULL){
        inorder(root->left, subtree);
        bool x = match(root, subtree);
        if(x){
            ans = x;
        }
        inorder(root->right, subtree);
    }
}

int main(){
    node* root = NULL;
    node* subtree = NULL;

    buildNode(root);
    buildNode(subtree);

    inorder(root, subtree);
    cout<<ans;
}
// 3 4 5 1 2 -1 -1 -1 -1 -1 -1
// 4 1 2 -1 -1 -1 -1

// 3 4 5 1 2 -1 -1 -1 -1 0 -1 -1 -1
// 4 1 2 -1 -1 -1 -1