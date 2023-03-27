

#include <iostream>
#include<queue>
#include<algorithm>
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
};

pair<int, int> diameter(node* root){
    if(root == NULL){
        pair<int,int> p= make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    int op1 = left.first;
    
    int op2 = right.first;
    int op3 = left.second + right.second + 1 ;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int check(node* root){
    if(root == NULL){
        return 0;
    }
cout<<"hello"<<" ";
    // int left = check(root->left);
    int right = check(root->right);
    right++;
    return right;
}

int main(){
    node* root = NULL;
    levelOrderTree(root);
    // levelOrderTraversal(root);
    cout<<"Diameter of tree is "<< diameter(root).first<<endl;
    cout<<"count is : "<<check(root);

    // 1 2 3 -1 -1 -1 4 -1 -1
}