// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include <iostream>
#include <queue>
#include<vector>
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

vector<int> zigZagTraversal(node* root)
{
    vector<int> ans;
    vector<int> nodes;
    queue<node*> q;
    nodes.clear();
    int level = 1;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (level % 2 == 0)
            {
                for (int i = nodes.size() - 1; i >= 0; i--)
                {
                    ans.push_back(nodes[i]);
                }

                nodes.clear();
                level++;
            }
            else
            {
                for (int i = 0; i < nodes.size(); i++)
                {
                    ans.push_back(nodes[i]);
                }
                nodes.clear();
                level++;
            }

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            nodes.push_back(temp->data);

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}

int main(){
    node* root = NULL;
    
    buildNode(root);

   vector<int> ans = zigZagTraversal(root);
   for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<" ";
   }
}