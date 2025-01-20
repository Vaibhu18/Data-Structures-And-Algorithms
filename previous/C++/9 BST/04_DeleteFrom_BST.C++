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

node* deleteFromBST(node* root, int val){
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        // for left child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // for right child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int minval = minVal(root->right)->data;
            root->data = minval;
            root->right = deleteFromBST(root->right, minval);
            return root;
        }
    }else if(val < root->data){
            root->left = deleteFromBST(root->left, val);
        }else{
            root->right = deleteFromBST(root->right, val);
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


int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    inOrderTraversal(root);
    deleteFromBST(root, 90);
    cout<<endl;
    inOrderTraversal(root);
}

// 50 20 70 10 30 90 110 -1