// https://leetcode.com/problems/same-tree/submissions/923429363/

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data : ";
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to right " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inOrderTraversal(node* p,vector<int> &inp )
{
    if (p != NULL)
    {
    inOrderTraversal(p->left, inp);
    inp.push_back(p->data);
    inOrderTraversal(p->right, inp);
    }else{
    inp.push_back(10000);
    }   
}

 void preOrderTraversal(node* p,vector<int> &inp )
{
    if (p != NULL)
    {
    inp.push_back(p->data);
    preOrderTraversal(p->left, inp);
    preOrderTraversal(p->right, inp);
    }else{
    inp.push_back(10000);
    }   
}

int main(){
    node *root1 = NULL;
    root1 = buildTree(root1);

    node *root2 = NULL;
    root2 = buildTree(root2);

    vector<int> inp, inq, prep, preq;
        inOrderTraversal(root1, inp);
        inOrderTraversal(root2, inq);
        preOrderTraversal(root1, prep);
        preOrderTraversal(root2, preq);

        if(inp == inq && prep == preq){
            cout<<"True"<<endl;
        }else{
            cout<<"False"<<endl;
        }
}

// 1 2 -1 -1 3 -1 -1
// 1 4 -1 -1 3 -1 -1