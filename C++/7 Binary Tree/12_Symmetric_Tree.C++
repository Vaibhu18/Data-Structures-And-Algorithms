

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// bool ans = false;
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

bool match(node* root1,node* root2){
    if(root1 != NULL && root2 != NULL){
        bool a = match(root1->left, root2->right);
        bool b = match(root1->right, root2->left);

        if((root1->data == root2->data) && a && b){
            return true;
        }else{
            return false;
        }
    }else if(root1 == NULL && root2 == NULL){
            return true;
        }else{
            return false;
        }
    return true;
}

int main(){
    node* root = NULL;
    
    buildNode(root);
    // bool ans = false;
    cout<<match(root->left,root->right);
    // cout<<ans;
   
}

// 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1