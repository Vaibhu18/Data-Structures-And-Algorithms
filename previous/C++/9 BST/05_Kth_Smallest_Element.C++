// https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=1

#include <iostream>
#include <queue>
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

void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int solve(node* root, int &i, int k){
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i, k);
    if(left != -1){
        return left;
    }

    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right, i, k);
}

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    int i = 0;
    int k = 5;
    int ans = solve( root, i, k);
    cout<<"Answer is : "<< ans;

}

// 50 20 70 10 30 90 110 -1