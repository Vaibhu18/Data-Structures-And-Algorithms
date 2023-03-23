// Count Leaf Nodes
// https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055

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

void inOrderTraversal(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inOrderTraversal(root->right, count);
}

int main(){
    int count = 0;
    node* root = NULL;
    buidFromLevelOrder(root);

    inOrderTraversal(root, count);
    cout<<"Count of leaf Node : "<<count;


}