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

bool searchInBST(node* root, int data){
    if(root == NULL)
        return false;

    if(root->data == data){
        return true;
    }    

    if(data > root->data){
        searchInBST(root->right, data);
    }else{
        searchInBST(root->left, data);
    }
}

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

node* minVal(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* maxVal(node* root){
    node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    // node* ans = ;
    cout<<"Min value of BST : "<< minVal(root)->data<<endl;
    cout<<"Max value of BST : "<< maxVal(root)->data;
}