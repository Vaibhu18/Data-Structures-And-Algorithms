#include <iostream>
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

node* buildTree(node* root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    
    root = new node(data);
 
    if(data == -1){
        return NULL;
    }
    
    cout<<"Enter data to left "<< data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to right "<< data<<endl;
    root->right = buildTree(root->right);

    return root;
}

node* print(node* root){
    if(root == NULL){
        return NULL;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main(){
    node* root = NULL;
    
    print(buildTree(root));
}