// https://practice.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

#include <iostream>
#include <queue>
#include <unordered_set>
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

void createNode(node* &root){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    root = new node(data);

    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter data for left of : "<< temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for right of : "<< temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

unordered_set<int> ans;
void verticalWidth(node* root, int hd){
    if(root== NULL){
        return ;
    }
    verticalWidth(root->left, hd-1);
    ans.insert(hd);
    verticalWidth(root->right, hd + 1);
}

int main(){
    node* root = NULL;
    createNode(root);
    ans.clear();
    verticalWidth(root, 0);
    cout<<ans.size();
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1