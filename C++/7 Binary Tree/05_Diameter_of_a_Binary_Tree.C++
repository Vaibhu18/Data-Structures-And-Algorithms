

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
int ans = 0;
int height(node* root){
   if(root == NULL){
       return 0;
   }
   int lh = height(root->left);
   int rh = height(root->right);
   ans = max(ans, lh+rh+1);
   return 1+max(lh, rh);
}

int main(){
    node* root = NULL;
    levelOrderTree(root);
    // levelOrderTraversal(root);
    cout<<"1st Approach Diameter of tree is "<< diameter(root).first<<endl;
    height(root);
    cout<<"2nd Approach Diameter of tree is "<< ans<< endl;;
    

    // 1 2 3 -1 -1 -1 4 -1 -1
}