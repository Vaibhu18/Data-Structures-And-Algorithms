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

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    int data = 6;
    bool ans = searchInBST(root, data);
    cout<<ans;
}