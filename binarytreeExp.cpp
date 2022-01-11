#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct TNode
{
    TNode *left;
    TNode *right;
    int data;
};

TNode *createNode(int data)
{
    TNode *newNode = new TNode();
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}

TNode *insert(TNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int findMax(TNode *root)
{
    TNode *current = root;
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return -1;
    }
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}
int findMin(TNode *root)
{
    TNode *current = root;
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return -1;
    }
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

bool search(TNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int height(TNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (lHeight > rHeight)
    {
        return (lHeight + 1);
    }
    else
    {
        return (rHeight + 1);
    }
}

int traversal(TNode *root)
{
}

int main()
{
    cout << "Running" << endl;
    TNode *root = NULL;

    root = insert(root, 20);
    insert(root, 10);
    insert(root, 45);
    insert(root, 15);
    insert(root, 35);
    insert(root, 5);
    insert(root, 17);
    cout << findMax(root) << endl;
    cout << findMin(root) << endl;
    search(root, 45) ? cout << "yes" << endl
                     : cout << "No" << endl;
    search(root, 56) ? cout << "yes" << endl
                     : cout << "No" << endl;
    cout << height(root);
}