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

// Level Order Traversal
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
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
}

// inOrderTraversal
void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// preOrderTraversal
void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// postOrderTraversal
void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

node *print(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{
    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // print(buildTree(root));
    root = buildTree(root);
    levelOrderTraversal(root);

    cout << "InOrder Traversal : ";
    inOrderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal : ";
    preOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal : ";
    postOrderTraversal(root);
}