// Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/submissions/925020930/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

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

void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
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

            if(temp ->right){
                q.push(temp->right);
            }
        }
    }
}

void invertBinaryTree(node* &root){
    if(root != NULL){
        swap(root->left, root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
}

// Approach 2nd
void invertBinaryTree2(node* &root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        if(temp != NULL){
            st.push(temp->left);
            st.push(temp->right);
            swap(temp->left, temp->right);
        }
    }
}

int main(){
    node* root = NULL;
    buildNode(root);
    levelOrderTraversal(root);
    invertBinaryTree(root);
    // invertBinaryTree2(root);
    levelOrderTraversal(root);
}
// 1 2 3 -1 -1 4 5 -1 -1 -1 -1