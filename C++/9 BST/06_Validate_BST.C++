// https://www.codingninjas.com/codestudio/problems/validate-bst_981275?leftPanelTab=0

#include <iostream>
#include <queue>
#include <limits.h> 
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

node* insertIntoBST(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }else{
        root->left = insertIntoBST(root->left, data);
    }
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

node *buildTree(node * root)
{
    cout << "Enter the data : ";
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to right " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

bool isBST(node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }else{
        return false;
    }
}

int main(){
    node* root = NULL;

    // cout<<"Enter data to create BST : "<<endl;
    // takeInput(root);
    root = buildTree(root);
    inOrderTraversal(root);
    bool ans = isBST(root, INT_MIN, INT_MAX);
    cout<<"Answer is : "<< ans;
}

// 50 20 70 10 30 90 110 -1
// valid BST : 5 2 -1 -1 8 4 -1 -1 9 -1 -1
// Invalid BST : 40 30 25 -1 -1 35 -1 -1 50 45 -1 -1 60 -1 -1
