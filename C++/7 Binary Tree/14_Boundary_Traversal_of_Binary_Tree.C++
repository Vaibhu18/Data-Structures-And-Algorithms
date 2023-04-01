// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <iostream>
#include <queue>
#include<vector>
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

// To traverse boundaries for a Binary tree
// traverse left side of BT
void leftView(node* root, vector <int> &ans){
    if((root== NULL) || root->left == NULL && root->right == NULL){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        leftView(root->left, ans);
    }else{
        leftView(root->right, ans);
    }
}

// Traverse Leaf nodes
void leafView(node* root, vector <int> &ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }

    leafView(root->left, ans);
    leafView(root->right, ans);
}

// Traverse Right side of BT
void rightView(node* root, vector<int> &ans){
    if((root== NULL) || root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        rightView(root->right, ans);
    }else{
        rightView(root->left, ans);
    }
    ans.push_back(root->data);
}

int main(){
    node* root = NULL;
    buildNode(root);

    vector <int> ans;
    if(root == NULL){
        cout<<"Node is NULL";
    }

    ans.push_back(root->data);

    // traverse left side of a BT
    leftView(root, ans);

    // traverse leaf nodes
    leafView(root->left, ans);
    leafView(root->right, ans);

    // traverse right side of BT
    rightView(root->right, ans);

    for(int i = 1; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

   // 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1  
}