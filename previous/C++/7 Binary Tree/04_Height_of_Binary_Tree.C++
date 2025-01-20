// Height of Binary Tree
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

#include <iostream>
#include<queue>
using namespace std;

class node{
    public : 
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTree(node* &root){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    root = new node(data);
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left of "<< temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for right of "<< temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// Get height of tree
int heightOfTree(node* root){
    if(root == NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int main(){
    node* root = NULL;
    levelOrderTree(root);
    levelOrderTraversal(root);
    cout<<"Height of tree is "<< heightOfTree(root)<<endl;
}